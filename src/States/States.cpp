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
    std::system("clear");
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
    std::system("clear");
    if (_string_input == "1")
    {
        return StateName::LOGIN;
    }
    else if (_string_input == "2")
    {
        return StateName::NEW_USER;
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

//-----LOGIN----------------------------------------------

StateLogin::StateLogin()
    : State(StateName::LOGIN)
{
}

void StateLogin::_entry()
{
    std::cout << LOGIN_TEXT;
    print_all_users(_user_umap);
    for (const auto &user : _user_umap)
    {
        _valid_input.push_back(std::to_string(user.first + 1));
    }
}

void StateLogin::_during()
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

StateName StateLogin::transitions()
{
    std::system("clear");
    if (_string_input == "0")
    {
        return StateName::START;
    }
    else
    {
        return StateName::USER_HOME;
    }
}

//-----NEW_USER----------------------------------------------

StateNewUser::StateNewUser()
    : State(StateName::NEW_USER)
{
}

void StateNewUser::_entry()
{
    std::cout << NEW_USER_TEXT;
}

void StateNewUser::_during() // TODO: Add option cancel in case users change their mind
{
    _string_input = get_string("Input: ");
    std::cout << std::endl;
    _user_id = add_user(_string_input, _user_umap).id();
}

StateName StateNewUser::transitions()
{
    std::system("clear");
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
    std::system("clear");
    if (_string_input == "1")
    {
        return StateName::JOIN_GROUP;
    }
    else if (_string_input == "2")
    {
        return StateName::NEW_GROUP;
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

//-----NEW_GROUP----------------------------------------------

StateNewGroup::StateNewGroup()
    : State(StateName::NEW_GROUP)
{
}

void StateNewGroup::_entry()
{
    std::cout << "\nHello " << _user_umap[_user_id].name() << "!\n";
    std::cout << NEW_GROUP_TEXT;
}

void StateNewGroup::_during() // TODO: Add option cancel in case users change their mind.
{
    _string_input = get_string("Input: ");
    std::cout << std::endl;
    _group_id = add_group(_string_input, _group_umap);
    add_user_to_group(_user_umap[_user_id], _group_umap[_group_id]);
}

StateName StateNewGroup::transitions()
{
    std::system("clear");
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
    std::cout << CHOOSE_GROUP_TEXT;
    _user_umap[_user_id].print_user_groups(_group_umap);
    std::cout << std::endl;

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
    std::system("clear");
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
    std::cout << JOIN_GROUP_TEXT;
    _user_umap[_user_id].print_unjoined_groups(_group_umap);
    std::cout << std::endl;

    for (const auto &group : _group_umap)
    {
        const auto &group_id = _user_umap[_user_id].group_ids();
        auto it = std::find(group_id.begin(), group_id.end(), group.first);
        if (it == group_id.end())
        {
            _valid_input.push_back(std::to_string(group.first + 1));
        }
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
    _valid_input = {};
    std::system("clear");
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
    std::system("clear");

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
    std::system("clear");
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

        if (_string_input == "00")
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
    std::cout << ".--------------------------------------------------.\n";
    std::cout << "| For whom are your paying?                        |\n";
    _group_umap[_group_id].print_group_members(_user_umap, _group_umap);
    std::cout << "| (0) Finished                                     | \n";
    std::cout << "| (00) Cancel                                      |\n";
    std::cout << "*--------------------------------------------------*\n";

    while (true)
    {
        _string_input = get_string("Input: ");

        if (_string_input == "00")
        {
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
            expense_added = true;
            std::cout << std::endl;
            break;
        }

        auto it_valid_input = std::find(_valid_input.begin(), _valid_input.end(), _string_input);
        if (it_valid_input != _valid_input.end())
        {
            _valid_input.erase(it_valid_input);
            _payee_ids.push_back(std::stoi(_string_input) - 1); // payee_id = user_input-1
        }
        else
        {
            try
            {
                auto it_payee_ids = std::find(_payee_ids.begin(), _payee_ids.end(), std::stoi(_string_input) - 1);
                if (it_payee_ids != _payee_ids.end())
                {
                    std::cout << "You have already input this member.\n";
                    continue;
                }
                else
                {
                    std::cout << "This member does not exist.\n";
                }
            }
            catch (const std::exception &error)
            {
                std::cerr << "Warning: " << error.what() << "\n";
                std::cout << ERROR_TEXT;
            }
        }
    }

    add_expense_to_group(_float_input * 100, _user_id, _payee_ids, _group_umap[_group_id], _user_umap);
}

StateName StateAddExpense::transitions()
{
    std::system("clear");
    _payee_ids = {};
    _valid_input = {};
    if (expense_added)
    {
        expense_added = false;
        return StateName::CHECK_EXPENSE;
    }
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
    std::cout << CHECK_EXPENSE_TEXT;
    print_expenses(_group_id, _user_umap, _group_umap);

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
    std::system("clear");
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
    std::cout << "-------------------------------------------------\n"; // TODO: update text to be in a box
    // TODO: First show who owes who and ask if group members want to settle, donnot settle if user doesnt choose to do so
    _group_umap[_group_id].create_settlement(_user_umap);
    std::cout << std::endl;
    std::cout << "(0) Back\n";
    std::cout << "-------------------------------------------------\n";
}

void StateSettlement::_during()
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

StateName StateSettlement::transitions()
{
    std::system("clear");
    return StateName::GROUP_HOME;
}

//-----LEAVE_GROUP----------------------------------------------

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
    if (_user_umap[_user_id].balance()[_group_id] != 0)
    {
        std::cout << "You could not leave this group yet, ";
        if (_user_umap[_user_id].balance()[_group_id] < 0)
        {
            std::cout << "pay your debt first.\n\n";
        }
        else if (_user_umap[_user_id].balance()[_group_id] > 0)
        {
            std::cout << "some body still owes you money.\n\n";
        }
        std::cout << "(0) Back\n";

        while (true)
        {
            _string_input = get_string("Input: ");

            if (_string_input == "0")
            {
                std::cout << std::endl;
                return;
            }
            else
            {
                std::cout << ERROR_TEXT;
            }
        }
    }

    while (true)
    {
        _string_input = get_string("Are you sure you want to leave this group? You can join back anytime.\n\n(1) Leave     (00) Cancel\n");

        if (_string_input == "0")
        {
            std::cout << std::endl;
            break;
        }
        else if (_string_input == "1")
        {
            remove_user_from_group(_user_umap[_user_id], _group_umap[_group_id]);
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
    std::system("clear");
    auto user_groupids = _user_umap[_user_id].group_ids();
    auto it = std::find(user_groupids.begin(), user_groupids.end(), _group_id);
    if (it == user_groupids.end())
    {
        return StateName::USER_HOME;
    }
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
            _group_umap[_group_id].edit_expenses(_expense_id, float_amount * 100);
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
    std::system("clear");
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

StateName StateBalance::transitions()
{
    std::system("clear");
    return StateName::GROUP_HOME;
}

//-----AUTO_GEN----------------------------------------------

StateAutoGen::StateAutoGen()
    : State(StateName::AUTO_GEN)
{
}

void StateAutoGen::_entry()
{
    // start clock
    start = std::chrono::system_clock::now();

    _path = "../autogenerated_data/autogenerated_file.csv"; // path from Build/ExpenseTracker.exe to autogenerated_file.csv
    std::ifstream file(_path);
    import_data(file, _auto_gen_user_umap, _auto_gen_group_umap);
}

void StateAutoGen::_during()
{
    auto_run(_auto_gen_user_umap, _auto_gen_group_umap);

    _auto_gen_user_umap = {};
    _auto_gen_group_umap = {};

    // stop clock
    end = std::chrono::system_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
    std::cout << std::endl;
    std::cout << "Elapsed time: " << elapsed.count() / 1000.0 << " seconds" << std::endl;

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
    std::system("clear");
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
