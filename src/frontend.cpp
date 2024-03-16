#include "../inc/frontend.h"

void update_terminal(int screen_id, int user_id, int group_id,
                     std::vector<User> &user_list, std::vector<Group> &group_list)
{

    if (screen_id == 1)
    { // Start screen
        std::cout << "\n############################################\n";
        std::cout << "(1) Login\n";
        std::cout << "(2) Create new user\n";
        std::cout << "(0) Exit\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 2)
    { // Login screen
        std::cout << "\n############################################\n";
        print_all_users(user_list);
        if (not user_list.empty())
        {
            std::cout << "(0) Back\n";
        }
        std::cout << "############################################\n";
    }
    else if (screen_id == 3)
    { // Create User screen
        std::cout << "\n############################################\n";
        std::cout << "Enter your user name!\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 4)
    { // User screen
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "(1) Join group\n";
        std::cout << "(2) Create group\n";
        std::cout << "(3) My groups\n";
        std::cout << "(0) Log-out\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 5)
    { // Join group screen
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        print_all_groups(group_list);
        if (not group_list.empty())
        {
            std::cout << "(0) Back\n";
        }
        std::cout << "############################################\n";
    }
    else if (screen_id == 6)
    { // Create group
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "Enter the group name!\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 7)
    { // group screen
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "You are in group: " << group_list[group_id].name() << ".\n";
        std::cout << "(1) Add expense\n";
        std::cout << "(2) Check expenses\n";
        std::cout << "(3) My balance\n";
        std::cout << "(4) Create Settlement\n";
        std::cout << "(5) Group members\n";
        std::cout << "(6) Leave group\n";
        std::cout << "(0) Back\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 8)
    { // Add expense
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "You are in group: " << group_list[group_id].name() << ".\n";
        std::cout << "Add expense!\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 9)
    { // Check expences
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "You are in group: " << group_list[group_id].name() << ".\n";
        print_expenses(group_id, user_list, group_list);
        if (not group_list[group_id].expenses().empty())
        {
            std::cout << "(0) Back\n";
        }
        std::cout << "############################################\n";
    }
    else if (screen_id == 10)
    { // User groups
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        print_user_groups(user_id, user_list, group_list);

        if (not user_list[user_id].group_ids().empty())
        {
            std::cout << "(0) Back\n";
        }
        std::cout << "############################################\n";
    }
    else if (screen_id == 11)
    { // Create Settlement
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        group_list[group_id].create_settlement(user_list);
        std::cout << "\n(0) Back\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 12)
    { // Leave group
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "ToDo: leave group\\";
        std::cout << "(0) Back\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 13)
    { // Edit Expense
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "You are in group: " << group_list[group_id].name() << ".\n";
        std::cout << "Change expense!\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 14)
    { // Group members
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "You are in group: " << group_list[group_id].name() << ".\n";
        group_list[group_id].print_group_members(user_list, group_list);
        std::cout << "(0) Back\n";
        std::cout << "############################################\n";
    }
    else if (screen_id == 15)
    { // See my balance
        std::cout << "\n############################################\n";
        std::cout << "Hello " << user_list[user_id].name() << "!\n";
        std::cout << "You are in group: " << group_list[group_id].name() << ".\n";
        user_list[user_id].show_balance(group_id);
        std::cout << "(0) Back\n";
        std::cout << "############################################\n";
    }
}

void get_and_compute_input(int &input_int, float &input_float, std::string &input_str,
                           int &screen_id, int &user_id, int &group_id,
                           std::vector<User> &user_list, std::vector<Group> &group_list)
{

    // TODO: Design a finite state machine using states instead of switch case
    switch (screen_id)
    {

    case 0: // Exit
        break; 

    case 1: // Start screen

        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 0;
        }
        else if (input_int == 1)
        {
            screen_id = 2;
        }
        else if (input_int == 2)
        {
            screen_id = 3;
        }

        break;

    case 2: // Login screen

        if (user_list.empty())
        {
            screen_id = 1;
            break;
        }

        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 1;
        }
        else
        {
            if (input_int - 1 < user_list.size())
            {
                screen_id = 4;
                user_id = input_int - 1;
            }
            else
            {
                screen_id = 2;
                std::cout << "Invalid user! Please try again.";
            }
        }

        break;

    case 3: // Create User screen
        std::cout << "Username: ";
        std::cin >> input_str;

        user_id = add_user(input_str, user_list).id();
        screen_id = 4;

        break;

    case 4: // User screen
        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 1;
        }
        else if (input_int == 1)
        {
            screen_id = 5;
        }
        else if (input_int == 2)
        {
            screen_id = 6;
        }
        else if (input_int == 3)
        {
            screen_id = 10;
        }

        break;

    case 5: // Join group screen

        if (group_list.empty())
        {
            screen_id = 4;
            break;
        }

        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 4;
        }
        else
        {
            std::cout << "here\n";
            add_user_to_group(user_list[user_id], group_list[input_int - 1]);
            group_id = group_list[input_int - 1].id();
            screen_id = 7;
        }

        break;

    case 6: // Create group
        std::cout << "group Name: ";
        std::cin >> input_str;

        group_id = add_group(input_str, group_list).id();
        add_user_to_group(user_list[user_id], group_list[group_id]);
        screen_id = 7;

        break;

    case 7: // group screen

        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 4;
        }
        else if (input_int == 1)
        {
            screen_id = 8;
        }
        else if (input_int == 2)
        {
            screen_id = 9;
        }
        else if (input_int == 3)
        {
            screen_id = 15;
        }
        else if (input_int == 4)
        {
            screen_id = 11;
        }
        else if (input_int == 5)
        {
            screen_id = 14;
        }
        else if (input_int == 6)
        {
            screen_id = 12;
        }

        break;

    case 8: // Add expense
    {
        int user_input{};
        std::vector<int> payee_ids{};
        std::cout << "Add expense in Euro: ";
        std::cin >> input_float;
        std::cout << "For whom are your paying?" << std::endl;
        group_list[group_id].print_group_members(user_list, group_list);
        std::cout << "(0) Finished" << std::endl;
        while (1)
        {
            std::cin >> user_input;
            if (user_input == 0)
            {
                break;
            };
            payee_ids.push_back(user_input - 1); // payee_id = user_input-1
        };
        add_expense_to_group(input_float * 100, user_id, payee_ids, group_list[group_id], user_list);

        screen_id = 7;

        break;
    }

    case 9: // Check expences

        if (group_list[group_id].expenses().empty())
        {
            screen_id = 7;
            break;
        }

        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 7;
        }

        break;

    case 10: // User groups

        if (user_list[user_id].group_ids().empty())
        {
            screen_id = 4;
            break;
        }

        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 4;
        }
        else
        {
            group_id = input_int - 1;
            screen_id = 7;
        }

        break;

    case 11: // Create Settlement
        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 7;
        }

        break;

    case 12: // Leave group
        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 7;
        }

        break;

    case 13: // Change expense
        std::cout << "Change expense to Euro: ";
        std::cin >> input_float;

        std::cout << input_int << input_float;
        edit_expense(group_list[group_id], input_int - 1, input_float * 100);
        screen_id = 7;

        break;

    case 14: // See group members
        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 7;
        }
        break;

    case 15: // See my balance
        std::cout << "Input: ";
        std::cin >> input_int;

        if (input_int == 0)
        {
            screen_id = 7;
        }
        break;
    }
}