#include "../inc/backend.h"
#include <algorithm>

User add_user(std::string name, std::vector<User> &user_list)
{
    for (const auto &user : user_list)
    {
        if (user.name().compare(name) == 0)
        {
            return user; // User with the given name already exists, exit the function
        }
    }

    // User not found, create a new one
    User new_user(name, user_list.size());
    user_list.push_back(new_user);
    return new_user;
}

void add_user_to_group(User &user, Group &group)
{
    for(const auto& member_id: group.member_ids()){
        if(user.id()==member_id) {
            return;
        }
    }
        group.add_member(user.id());
        user.join_group(group.id());
}

Group add_group(std::string group_name, std::vector<Group> &group_list)
{
    for (const auto &group : group_list)
    {
        if (group.name().compare(group_name) == 0)
        {
            return group;
        }
    }
    Group new_group(group_name, group_list.size());
    group_list.push_back(new_group);

    return new_group;
}

Expense add_expense_to_group(int amount, int payer_id, std::vector<int> payee_ids, Group &group, std::vector<User> &user_list)
{
    Expense expense(group.expenses().size(), amount, payer_id, payee_ids);
    group.add_expense(expense);
    group.update_member_balance(expense, user_list);
    return expense;
}

void edit_expense(Group &group, int expense_id, int new_amount)
{
    group.edit_expenses(expense_id, new_amount);
}
