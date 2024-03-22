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
    while (true)
    {
        _string_input = get_string("Input: ");
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateInit::transitions()
{
    if (_string_input == "1")
    {
        return StateName::START;
    }
    else if (_string_input == "2")
    {
        return StateName::AUTO_GEN;
    }
    else if (_string_input == "00")
    {
        return StateName::EXIT;
    }
    else
    {
        std::cout << "Something very wrong has just happened, we should not been able to land here.";
        return StateName::EXIT;
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
    while (true)
    {
        _string_input = get_string("Input: ");
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateStart::transitions()
{
    if (_string_input == "1")
    {
        return StateName::CHOOSE_USER;
    }
    else if (_string_input == "2")
    {
        return StateName::CREATE_USER;
    }
    else if (_string_input == "0")
    {
        return StateName::INIT;
    }
    else if (_string_input == "00")
    {
        return StateName::EXIT;
    }
    else
    {
        std::cout << "Something very wrong has just happened, we should not been able to land here.";
        return StateName::EXIT;
    }
}

//-----CHOOSE_USER----------------------------------------------

StateChooseUser::StateChooseUser()
    : State(StateName::CHOOSE_USER)
{
}

void StateChooseUser::_entry()
{
    std::cout << "-------------------------------------------------\n";
    print_all_users(_user_umap);
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";
    for (const auto &user : _user_umap)
    {
        _valid_input.push_back(std::to_string(user.first + 1));
    }
}

void StateChooseUser::_during()
{
    while (true)
    {
        _string_input = get_string("Input: ");
        if (_string_input == "0")
        {
            std::cout << std::endl;
            break;
        }
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            _user_id = std::stoi(_string_input) - 1;
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateChooseUser::transitions()
{
    if (_string_input == "0")
    {
        return StateName::START;
    }
    else
    {
        return StateName::USER_HOME;
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
    _string_input = get_string("Input: ");
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
    while (true)
    {
        _string_input = get_string("Input: ");
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateUserHome::transitions()
{
    if (_string_input == "1")
    {
        return StateName::JOIN_GROUP;
    }
    else if (_string_input == "2")
    {
        return StateName::CREATE_GROUP;
    }
    else if (_string_input == "0")
    {
        return StateName::START;
    }
    else if (_string_input == "3")
    {
        return StateName::CHOOSE_GROUP;
    }
    else
    {
        std::cout << "Something very wrong has just happened, we should not been able to land here.";
        return StateName::EXIT;
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
    _string_input = get_string("Input: ");
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
    std::cout << "-------------------------------------------------\n";
    print_user_groups(_user_id, _user_umap, _group_umap);
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";

    const auto &group_ids = _user_umap[_user_id].group_ids();
    for (const auto &id : group_ids)
    {
        _valid_input.push_back(std::to_string(id + 1));
    }
}

void StateChooseGroup::_during()
{
    while (true)
    {
        _string_input = get_string("Input: ");
        if (_string_input == "0")
        {
            std::cout << std::endl;
            break;
        }
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            _group_id = std::stoi(_string_input) - 1;
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateChooseGroup::transitions()
{
    if (_string_input == "0")
    {
        return StateName::USER_HOME;
    }
    else
    {
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
    std::cout << "-------------------------------------------------\n";
    print_all_groups(_group_umap);
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";

    for (const auto &group : _group_umap)
    {
        _valid_input.push_back(std::to_string(group.first + 1));
    }
}

void StateJoinGroup::_during()
{
    while (true)
    {
        _string_input = get_string("Input: ");
        if (_string_input == "0")
        {
            std::cout << std::endl;
            break;
        }
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            _group_id = std::stoi(_string_input) - 1;
            add_user_to_group(_user_umap[_user_id], _group_umap[_group_id]);
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateJoinGroup::transitions()
{
    if (_string_input == "0")
    {
        return StateName::USER_HOME;
    }
    else
    {
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
    while (true)
    {
        _string_input = get_string("Input: ");
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateGroupHome::transitions()
{

    if (_string_input == "0")
    {
        return StateName::USER_HOME;
    }
    else if (_string_input == "1")
    {
        return StateName::ADD_EXPENSE;
    }
    else if (_string_input == "2")
    {
        return StateName::CHECK_EXPENSE;
    }
    else if (_string_input == "3")
    {
        return StateName::BALANCE;
    }
    else if (_string_input == "4")
    {
        return StateName::SETTLEMENT;
    }
    else if (_string_input == "5")
    {
        return StateName::GROUP_MEMBER;
    }
    else if (_string_input == "6")
    {
        return StateName::LEAVE_GROUP;
    }
    else
    {
        std::cout << "Something very wrong has just happened, we should not been able to land here.";
        return StateName::EXIT;
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
    std::cout << "-------------------------------------------------\n";
    _group_umap[_group_id].print_group_members(_user_umap, _group_umap);
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";
}

void StateGroupMember::_during()
{
    while (true)
    {
        _string_input = get_string("Input: ");

        if (_string_input == "0")
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateGroupMember::transitions()
{
    return StateName::GROUP_HOME;
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

    const auto &member_ids = _group_umap[_group_id].member_ids();
    for (auto id : member_ids)
    {
        _valid_input.push_back(std::to_string(id + 1));
    }
}

void StateAddExpense::_during()
{

    while (true)
    {
        _string_input = get_string("Input: ");

        if (_string_input == "0")
        {
            std::cout << std::endl;
            return;
        }
        try
        {
            _float_input = std::stof(_string_input);
            break;
        }
        catch (const std::exception &error)
        {
            std::cerr << "Warning: " << error.what() << "\n";
            std::cout << ERROR_TEXT;
        }
    }

    std::cout << std::endl;
    std::cout << "For whom are your paying?" << std::endl;
    _group_umap[_group_id].print_group_members(_user_umap, _group_umap);
    std::cout << std::endl;
    std::cout << "(0) Finished" << std::endl;
    std::cout << "(00) Cancel" << std::endl;

    while (true)
    {
        _string_input = get_string("Input: ");

        if (_string_input == "00")
        {
            _payee_ids = {};
            return;
        }

        if (_string_input == "0")
        {
            if (_payee_ids.empty())
            {
                std::cout << std::endl;
                std::cout << "Please input the payee(s) first!\n";
                std::cout << "(To cancel input (00))\n";
                continue;
            }
            std::cout << std::endl;
            break;
        }

        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            // TODO: Right now if a user is accidentally input multiple times,
            // it will just be added to payee_id multiple times, which will cause calculation errors. This needs to be fixed
            _payee_ids.push_back(std::stoi(_string_input) - 1); // payee_id = user_input-1
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }

    add_expense_to_group(_float_input * 100, _user_id, _payee_ids, _group_umap[_group_id], _user_umap);
    _payee_ids = {};
    _valid_input = {};
}

StateName StateAddExpense::transitions()
{
    return StateName::GROUP_HOME;
}

//-----CHECK_EXPENSE----------------------------------------------

StateCheckExpense::StateCheckExpense()
    : State(StateName::CHECK_EXPENSE)
{
}

void StateCheckExpense::_entry()
{
    const auto &expenses = _group_umap[_group_id].expenses();
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << "-------------------------------------------------\n";
    print_expenses(_group_id, _user_umap, _group_umap);

    if (not expenses.empty())
    {
        std::cout << "\n(Input the number before each expense to edit)\n";
    }
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";

    for (const auto &expense : expenses)
    {
        _valid_input.push_back(std::to_string(expense.id() + 1));
    }
}

void StateCheckExpense::_during()
{
    while (true)
    {
        _string_input = get_string("Input: ");

        if (_string_input == "0")
        {
            std::cout << std::endl;
            break;
        }

        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            _expense_id = std::stoi(_string_input) - 1;
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateCheckExpense::transitions()
{
    if (_string_input == "0")
    {
        return StateName::GROUP_HOME;
    }
    else
    {
        return StateName::EDIT_EXPENSE;
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
    std::cout << "-------------------------------------------------\n";
    _group_umap[_group_id].create_settlement(_user_umap);
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";
}

void StateSettlement::_during()
{
    while (true)
    {
        _unsigned_input = get_unsigned("Input: ");
        if (_unsigned_input == 0)
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateSettlement::transitions()
{
    return StateName::GROUP_HOME;
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
    while (true)
    {
        _unsigned_input = get_unsigned("Input: ");
        if (_unsigned_input == 0)
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateLeaveGroup::transitions()
{
    return StateName::GROUP_HOME;
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
    while (true)
    {
        _string_input = get_string("Input: ");

        if (_string_input == "00")
        {
            std::cout << std::endl;
            break;
        }

        try
        {
            auto float_amount = std::stof(_string_input);
            edit_expense(_group_umap[_group_id], _expense_id, float_amount * 100);
            std::cout << "Expense successfully edited!";
            break;
        }
        catch (const std::exception &error)
        {
            std::cerr << "Warning: " << error.what() << "\n";
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateEditExpense::transitions()
{
    return StateName::CHECK_EXPENSE;
}

//-----BALANCE----------------------------------------------

StateBalance::StateBalance()
    : State(StateName::BALANCE)
{
}

void StateBalance::_entry()
{
    std::cout << "Hello " << _user_umap[_user_id].name() << "!\n";
    std::cout << "You are in group: " << _group_umap[_group_id].name() << ".\n";
    std::cout << "-------------------------------------------------\n";
    _user_umap[_user_id].show_balance(_group_id);
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";
}

void StateBalance::_during()
{
    while (true)
    {
        _unsigned_input = get_unsigned("Input: ");
        if (_unsigned_input == 0)
        {
            std::cout << std::endl;
            break;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateBalance::transitions()
{
    return StateName::GROUP_HOME;
}

//-----AUTO_GEN----------------------------------------------

// TODO:Before get in the group,all old data of user and group list has to be deleted
// or a nwe data containers have to be defined.

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
    std::cout << std::endl;
    std::cout << "(0) Mode\n";
    std::cout << "(00) Exit\n";
    while (true)
    {
        _string_input = get_string("Input: ");
        auto it = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it != _valid_input.end())
        {
            break;
            std::cout << std::endl;
        }
        else
        {
            std::cout << ERROR_TEXT;
        }
    }
}

StateName StateAutoGen::transitions()
{
    if (_string_input == "0")
    {
        return StateName::INIT;
    }
    else if (_string_input == "00")
    {
        return StateName::EXIT;
    }
    else
    {
        std::cout << "Something very wrong has just happened, we should not been able to land here.";
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
    return StateName::EXIT;
}
