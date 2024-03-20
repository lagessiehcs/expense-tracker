#include "../../inc/States/States.h"
#include <iostream>
#include "../../inc/printers.h"

//-----INIT----------------------------------------------

StateInit::StateInit()
    : State(StateName::INIT)
{
}

void StateInit::_entry()
{
    std::cout << INIT_TEXT;
}

void StateInit::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
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

void StateStart::_entry()
{
    std::cout << START_TEXT;
}

void StateStart::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateStart::transitions()
{
    switch (_unsigned_input)
    {
    case 0:
        return StateName::EXIT;

    case 1:
        return StateName::CHOOSE_USER;

    case 2:
        return StateName::CREATE_USER;

    default:
        std::cout << ERROR_TEXT;
        return StateName::START;
    }
}

//-----CHOOSE_USER----------------------------------------------

StateChooseUser::StateChooseUser()
    : State(StateName::CHOOSE_USER)
{
}

void StateChooseUser::_entry()
{
    std::cout << "=================================================\n";
    print_all_users(_user_umap);
    if (not _user_umap.empty())
    {
        std::cout << "(0) Back\n";
    }
    std::cout << "=================================================\n";
}

void StateChooseUser::_during()
{
    std::cout << "Input: ";
}

StateName StateChooseUser::transitions()
{
    if (_user_umap.empty())
    {
        return StateName::START;
    }

    _unsigned_input = get_unsigned();
    std::cout << std::endl;

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

void StateCreateUser::_entry()
{
    std::cout << CREATE_USER_TEXT;
}

void StateCreateUser::_during()
{
    std::cout << "Input: ";
    _string_input = get_string();
    std::cout << std::endl;
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

void StateUserHome::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << USER_HOME_TEXT;
}

void StateUserHome::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
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

    default:
        std::cout << ERROR_TEXT;
        return StateName::USER_HOME;
    }
}

//-----CREATE_GROUP----------------------------------------------

StateCreateGroup::StateCreateGroup()
    : State(StateName::CREATE_GROUP)
{
}

void StateCreateGroup::_entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << CREATE_GROUP_TEXT;
}

void StateCreateGroup::_during()
{
    std::cout << "Input: ";
    _string_input = get_string();
    std::cout << std::endl;
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

void StateChooseGroup::_entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "=================================================\n";
    print_all_groups(_group_umap);
    if (not _group_umap.empty())
    {
        std::cout << "(0) Back\n";
    }
    std::cout << "=================================================\n";
}

void StateChooseGroup::_during()
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

void StateJoinGroup::_entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "=================================================\n";
    print_all_groups(_group_umap);
    if (not _group_umap.empty())
    {
        std::cout << "(0) Back\n";
    }
    std::cout << "=================================================\n";
}

void StateJoinGroup::_during()
{
}

StateName StateJoinGroup::transitions()
{
    if (_group_umap.empty())
    {
        return StateName::USER_HOME;
    }

    _unsigned_input = get_unsigned();

    switch (_unsigned_input)
    {
    case 0:
        return StateName::START;

    default:
        add_user_to_group(_user_umap[_user_id], _group_umap[_unsigned_input - 1]);
        _group_id = _group_umap[_unsigned_input - 1].id();
        return StateName::GROUP_HOME;
    }
}

//-----GROUP_HOME----------------------------------------------

StateGroupHome::StateGroupHome()
    : State(StateName::GROUP_HOME)
{
}

void StateGroupHome::_entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << GROUP_HOME_TEXT;
}

void StateGroupHome::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateGroupHome::transitions()
{
    switch (_unsigned_input)
    {
    case 0:
        return StateName::USER_HOME;

    case 1:
        return StateName::ADD_EXPENSE;

    case 2:
        return StateName::CHECK_EXPENSE;

    case 3:
        return StateName::BALANCE;

    case 4:
        return StateName::SETTLEMENT;

    case 5:
        return StateName::GROUP_MEMBER;

    case 6:
        return StateName::LEAVE_GROUP;

    default:
        std::cout << ERROR_TEXT;
        return StateName::GROUP_HOME;
    }
}

//-----GROUP_MEMBER----------------------------------------------

StateGroupMember::StateGroupMember()
    : State(StateName::GROUP_MEMBER)
{
}

void StateGroupMember::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << "=================================================\n";
    _group_umap[_group_id].print_group_members(_user_umap, _group_umap);
    std::cout << "(0) Back\n";
    std::cout << "=================================================\n";
}

void StateGroupMember::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateGroupMember::transitions()
{
    if (_unsigned_input == 0)
    {
        return StateName::GROUP_HOME;
    }
}

//-----ADD_EXPENSE----------------------------------------------

StateAddExpense::StateAddExpense()
    : State(StateName::ADD_EXPENSE)
{
}

void StateAddExpense::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << ADD_EXPENSE_TEXT;
}

void StateAddExpense::_during()
{
    std::cout << "Add expense in Euro: ";
    _float_input = get_float();
    std::cout << "For whom are your paying?" << std::endl;
    _group_umap[_group_id].print_group_members(_user_umap, _group_umap);
    std::cout << "(0) Finished" << std::endl;
    while (1)
    {
        _unsigned_input = get_unsigned();
        if (_unsigned_input == 0)
        {
            break;
        };
        _payee_ids.push_back(_unsigned_input - 1); // payee_id = user_input-1
    };
    add_expense_to_group(_float_input * 100, _user_id, _payee_ids, _group_umap[_group_id], _user_umap);
}

StateName StateAddExpense::transitions()
{
    if (_unsigned_input == 0)
    {
        return StateName::GROUP_HOME;
    }
}

//-----CHECK_EXPENSE----------------------------------------------

StateCheckExpense::StateCheckExpense()
    : State(StateName::CHECK_EXPENSE)
{
}

void StateCheckExpense::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << "=================================================\n";
    print_expenses(_group_id, _user_umap, _group_umap);
    if (not _group_umap.find(_group_id)->second.expenses().empty())
    {
        std::cout << "(0) Back\n";
    }
    std::cout << "=================================================\n";
}

void StateCheckExpense::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateCheckExpense::transitions()
{
    if (_unsigned_input == 0)
    {
        return StateName::GROUP_HOME;
    }
}

//-----SETTLEMENT----------------------------------------------

StateSettlement::StateSettlement()
    : State(StateName::SETTLEMENT)
{
}

void StateSettlement::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << "=================================================\n";
    _group_umap[_group_id].create_settlement(_user_umap);
    std::cout << "\n(0) Back\n";
    std::cout << "=================================================\n";
}

void StateSettlement::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateSettlement::transitions()
{
    if (_unsigned_input == 0)
    {
        return StateName::GROUP_HOME;
    }
}

//-----LEAVE_GROUP----------------------------------------------
// TODO: Implement LEAVE_GROUP
StateLeaveGroup::StateLeaveGroup()
    : State(StateName::LEAVE_GROUP)
{
}

void StateLeaveGroup::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << LEAVE_GROUP_TEXT;
}

void StateLeaveGroup::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateLeaveGroup::transitions()
{
    if (_unsigned_input == 0)
    {
        return StateName::GROUP_HOME;
    }
}

//-----EDIT_EXPENSE----------------------------------------------

StateEditExpense::StateEditExpense()
    : State(StateName::EDIT_EXPENSE)
{
}

void StateEditExpense::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << EDIT_EXPENSE_TEXT;
}

void StateEditExpense::_during()
{
    std::cout << "Which expense do you want to change: ";
    _unsigned_input = get_unsigned();
    std::cout << "Amount you want to change to in Euro: ";
    _float_input = get_float();
    edit_expense(_group_umap[_group_id], _unsigned_input - 1, _float_input * 100);
    std::cout << "Done!";
}

StateName StateEditExpense::transitions()
{
    return StateName::GROUP_HOME;
}

//-----BALANCE----------------------------------------------
// TODO: Implement BALANCE

StateBalance::StateBalance()
    : State(StateName::BALANCE)
{
}

void StateBalance::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << "=================================================\n";
    _user_umap[_user_id].show_balance(_group_id);
    std::cout << "(0) Back\n";
    std::cout << "=================================================\n";
}

void StateBalance::_during()
{
    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateBalance::transitions()
{
    if (_unsigned_input == 0)
    {
        return StateName::GROUP_HOME;
    }
}

//-----AUTO_GEN----------------------------------------------

StateAutoGen::StateAutoGen()
    : State(StateName::AUTO_GEN)
{
}

void StateAutoGen::_entry()
{
    _path = "../autogenerated_data/autogenerated_file.csv"; // path from Build/ExpenseTracker.exe to autogenerated_file.csv
    std::ifstream file(_path);
    import_data(file, _user_umap, _group_umap);
}

void StateAutoGen::_during()
{
    auto_run(_user_umap, _group_umap);
    std::cout << "(0) Exit\n";

    std::cout << "Input: ";
    _unsigned_input = get_unsigned();
    std::cout << std::endl;
}

StateName StateAutoGen::transitions()
{
    if (_unsigned_input == 0)
    {
        return StateName::EXIT;
    }
}

//-----EXIT----------------------------------------------

StateExit::StateExit()
    : State(StateName::EXIT)
{
}

void StateExit::_entry()
{
    std::cout << EXIT_TEXT;
}

void StateExit::_during()
{
}

StateName StateExit::transitions()
{
    // If no transition specified, return the current State
    return StateName::EXIT;
}
