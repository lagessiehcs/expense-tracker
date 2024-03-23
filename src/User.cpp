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

void User::update_balance(unsigned group_id, unsigned balance)
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
