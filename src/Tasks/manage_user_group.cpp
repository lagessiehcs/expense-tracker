#include "../../inc/Tasks/manage_user_group.h"

User add_user(std::string name, std::unordered_map<unsigned, User> &user_list)
{
    for (const auto &user : user_list)
    {
        if (user.second.name().compare(name) == 0)
        {
            return user.second; // User with the given name already exists, exit the function
        }
    }

    // User not found, create a new one
    User new_user(name);
    auto id = new_user.id();
    user_list.emplace(std::make_pair(new_user.id(), new_user)); // Avoid using operator[] used, to avoid calling User constructor again
    return new_user;
}

void add_user_to_group(User &user, Group &group)
{
    for (const auto &member_id : group.member_ids())
    {
        if (user.id() == member_id)
        {
            return;
        }
    }
    group.add_member(user.id());
    user.join_group(group.id());
}

void remove_user_from_group(User &user, Group &group)
{
    group.remove_member(user.id());
    user.leave_group(group.id());
}

unsigned add_group(std::string group_name, std::unordered_map<unsigned, Group> &group_umap)
{
    for (const auto &group : group_umap)
    {
        if (group.second.name().compare(group_name) == 0)
        {
            return group.second.id();
        }
    }
    Group new_group(group_name);
    group_umap.emplace(std::make_pair(new_group.id(), new_group)); // Avoid using operator[] used, to avoid calling Group constructor again

    return new_group.id();
}

void add_expense_to_group(unsigned amount, unsigned payer_id, std::vector<unsigned> payee_ids, Group &group, std::unordered_map<unsigned, User> &user_list)
{
    group.add_expense(amount, payer_id, payee_ids);
    group.update_member_balance(amount, payer_id, payee_ids, user_list);
}
