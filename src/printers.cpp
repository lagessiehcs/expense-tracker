
#include "../inc/printers.h"

void print_all_users(const std::unordered_map<unsigned, User> &user_umap)
{

    if (user_umap.empty())
    {
        std::cout << "| No users yet! Go back and create a user!         |\n";
    }
    else
    {
        std::cout << "| Users:                                           |\n";
        for (const auto &[id, user] : user_umap)
        {
            std::string string = " (" + std::to_string(id + 1) + ") " + user.name();
            std::string spaces(50 - string.length(), ' ');
            std::cout << "|" << string << spaces << "|\n";
        }
    }
    std::cout << "|                                                  |\n";
    std::cout << "| (0) Back                                         |\n";
    std::cout << "*--------------------------------------------------*\n";
    return;
}

void print_all_groups(const std::unordered_map<unsigned, Group> &group_umap)
{

    if (group_umap.empty())
    {
        std::cout << "| No groups yet! Go back and create a group!       |\n";
    }
    else
    {
        std::cout << "| Groups:                                          |\n";
        for (const auto &[id, group] : group_umap)
        {
            std::string string = " (" + std::to_string(id + 1) + ") " + group.name();
            std::string spaces(50 - string.length(), ' ');
            std::cout << "|" << string << spaces << "|\n";
        }
    }
    std::cout << "|                                                  |\n";
    std::cout << "| (0) Back                                         |\n";
    std::cout << "*--------------------------------------------------*\n";
    return;
}

