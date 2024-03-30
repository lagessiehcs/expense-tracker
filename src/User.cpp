#include "../inc/User.h"
#include <cmath>

User::User(std::string name)
    : _name(name), _id(counter++)
{
}

std::string User::name() const
{
    return _name;
}

unsigned User::id() const
{
    return _id;
}

std::vector<unsigned> User::group_ids() const
{
    return _group_ids;
}

void User::join_group(unsigned group_id)
{
    _group_ids.push_back(group_id);
}

void User::leave_group(unsigned group_id)
{
    auto const it = std::find(_group_ids.begin(), _group_ids.end(), group_id);
    _group_ids.erase(it);
}

void User::set_balance(unsigned group_id, int balance)
{
    _balance[group_id] = balance;
}

void User::update_balance(unsigned group_id, int balance)
{
    _balance[group_id] += balance;
}

std::unordered_map<unsigned, int> User::balance()
{
    return _balance;
}

void User::show_balance(unsigned group_id)
{
    std::cout << "Your balance:\n";
    if (_balance[group_id] == 0)
    {
        std::cout << "You dont get nor owe any money.\n";
    }
    else if (_balance[group_id] > 0)
    {
        std::cout << "You get " << _balance[group_id] * 0.01 << " Euro.\n";
    }
    else
    {
        std::cout << "You owe " << -_balance[group_id] * 0.01 << " Euro.\n";
    }
}

void User::print_user_groups(const std::unordered_map<unsigned, Group> &group_umap)
{
    if (_group_ids.empty())
    {
        std::cout << "| You have not joined a group yet!                 |\n";
    }
    else
    {
        std::cout << "| My groups:                                       |\n";
        for (auto id : _group_ids)
        {
            std::string string = " (" + std::to_string(id + 1) + ") " + group_umap.find(id)->second.name();
            std::string spaces(50 - string.length(), ' ');
            std::cout << "|" << string << spaces << "|\n";
        }
    }
    std::cout << "|                                                  |\n";
    std::cout << "| (0) Back                                         |\n";
    std::cout << "*--------------------------------------------------*\n";
}

void User::print_unjoined_groups(const std::unordered_map<unsigned, Group> &group_umap)
{
    bool no_unjoined_group = true;
    if (group_umap.empty())
    {
        std::cout << "| No groups yet! Go back and create a group!       |\n";
    }
    else
    {
        for (const auto &group : group_umap)
        {
            const auto &it = std::find(_group_ids.begin(), _group_ids.end(), group.first);
            if (it == _group_ids.end())
            {
                no_unjoined_group = false;
                std::string string = " (" + std::to_string(group.first + 1) + ") " + group.second.name();
                std::string spaces(50 - string.length(), ' ');
                std::cout << "|" << string << spaces << "|\n";
            }
        }
        if (no_unjoined_group)
        {
            std::cout << "| You have joined all existed group!               |\n";
        }
    }

    std::cout << "|                                                  |\n";
    std::cout << "| (0) Back                                         |\n";
    std::cout << "*--------------------------------------------------*\n";
}