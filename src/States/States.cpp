#include "../../inc/States/States.h"
#include <iostream>
#include "../printers.h"

//-----INIT----------------------------------------------

StateInit::StateInit()
    : State(StateName::INIT)
{
}

void StateInit::entry()
{
    std::cout << INIT_TEXT;
}

void StateInit::during()
{
    _unsigned_input = get_unsigned();
}

StateName StateInit::transitions()
{
    switch (_unsigned_input)
    {
    case 1:
        return StateName::START;

    case 2:
        return StateName::AUTO_GEN;

    default:
        std::cout << ERROR_TEXT;
        return StateName::INIT;
    }
}

//-----START----------------------------------------------

StateStart::StateStart()
    : State(StateName::START)
{
}

void StateStart::entry()
{
    std::cout << START_TEXT;
}

void StateStart::during()
{
    _unsigned_input = get_unsigned();
}

StateName StateStart::transitions()
{
    switch (_unsigned_input)
    {
    case 0:
        return StateName::STOP;

    case 1:
        return StateName::CHOOSE_USER;

    case 2:
        return StateName::CREATE_USER;

    default:
        std::cout << ERROR_TEXT;
        return StateName::INIT;
    }
}

//-----CHOOSE_USER----------------------------------------------

StateChooseUser::StateChooseUser()
    : State(StateName::CHOOSE_USER)
{
}

void StateChooseUser::entry()
{
    std::cout << "\n=================================================\n";
    print_all_users(_user_umap);
    if (not user_umap.empty())
    {
        std::cout << "(0) Back\n";
    }
    std::cout << "=================================================\n";
}

void StateChooseUser::during()
{
}

StateName StateChooseUser::transitions()
{
    if (_user_umap.empty())
    {
        return StateName::START;
    }

    _unsigned_input = get_unsigned();

    switch (_unsigned_input)
    {
    case 0:
        return StateName::START;

    default:
        if (_unsigned_input - 1 < _user_umap.size())
        {
            _user_id = _unsigned_input - 1;
            return StateName::USER_HOME;
        }
        else
        {
            std::cout << ERROR_TEXT;
            return StateName::CHOOSE_USER;
        }
    }
}

//-----CREATE_USER----------------------------------------------

StateCreateUser::StateCreateUser()
    : State(StateName::CREATE_USER)
{
}

void StateCreateUser::entry()
{
    std::cout << CREATE_USER_TEXT;
}

void StateCreateUser::during()
{
    _string_input = get_string();
    _user_id = add_user(_string_input, _user_umap).id();
}

StateName StateCreateUser::transitions()
{
    return StateName::USER_HOME;
}

//-----USER_HOME----------------------------------------------

StateUserHome::StateUserHome()
    : State(StateName::USER_HOME)
{
}

void StateUserHome::entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << USER_HOME_TEXT;
}

void StateUserHome::during()
{
    _unsigned_input = get_unsigned();
}

StateName StateUserHome::transitions()
{
    switch (_unsigned_input)
    {
    case 0:
        return StateName::START;

    case 1:
        return StateName::JOIN_GROUP;

    case 2:
        return StateName::CREATE_GROUP;

    case 3:
        return StateName::CHOOSE_GROUP;
    }
}

//-----CREATE_GROUP----------------------------------------------

StateCreateGroup::StateCreateGroup()
    : State(StateName::CREATE_GROUP)
{
}

void StateCreateGroup::entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << CREATE_GROUP_TEXT;
}

void StateCreateGroup::during()
{
    _string_input = get_string();
    _group_id = add_group(_string_input, _group_umap);
    add_user_to_group(_user_umap[_user_id], _group_umap[_group_id]);
}

StateName StateCreateGroup::transitions()
{
    return StateName::GROUP_HOME;
}

//-----CHOOSE_GROUP----------------------------------------------

StateChooseGroup::StateChooseGroup()
    : State(StateName::CHOOSE_GROUP)
{
}

void StateChooseGroup::entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "\n=================================================\n";
    print_all_groups(_group_umap);
    if (not group_umap.empty())
    {
        std::cout << "(0) Back\n";
    }
    std::cout << "=================================================\n";
}

void StateChooseGroup::during()
{
}

StateName StateChooseGroup::transitions()
{
    if (_user_umap[_user_id].group_ids().empty())
    {
        return StateName::USER_HOME;
    }

    _unsigned_input = get_unsigned();

    switch (_unsigned_input)
    {
    case 0:
        return StateName::USER_HOME;

    default:
        _group_id = _unsigned_input - 1;
        return StateName::GROUP_HOME;
    }
}

//-----JOIN_GROUP----------------------------------------------

StateJoinGroup::StateJoinGroup()
    : State(StateName::JOIN_GROUP)
{
}

void StateJoinGroup::entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "\n=================================================\n";
    print_all_groups(_group_umap);
    if (not group_umap.empty())
    {
        std::cout << "(0) Back\n";
    }
    std::cout << "=================================================\n";
}

void StateJoinGroup::during()
{
}

StateName StateJoinGroup::transitions()
{
    if (_user_umap[_user_id].group_ids().empty())
    {
        return StateName::USER_HOME;
    }

    _unsigned_input = get_unsigned();

    switch (_unsigned_input)
    {
    case 0:
        return StateName::START;

    default:
        add_user_to_group(_user_umap[_user_id], _group_umap[_input_int - 1]);
        _group_id = _group_umap[_input_int - 1].id();
        return StateName::GROUP_HOME;
    }
}