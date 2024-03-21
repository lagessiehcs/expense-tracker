
#include "../inc/printers.h"

void print_all_users(const std::unordered_map<unsigned, User> &user_umap)
{

    if (user_umap.empty())
    {
        std::cout << "No users yet! Go back and create a user!\n";
    }
    else
    {
        std::cout << "Users:\n";
        for (const auto &[id, user] : user_umap)
        {
            std::cout << "(" << id + 1 << ") " << user.name() << "\n";
        }
    }
}

void print_all_groups(const std::unordered_map<unsigned, Group> &group_umap)
{

    if (group_umap.empty())
    {
        std::cout << "No groups yet! Go back and create a group!\n";
    }
    else
    {
        std::cout << "Groups: \n";
        for (const auto &[id, group] : group_umap)
        {
            std::cout << "(" << id + 1 << ") " << group.name() << "\n";
        }
    }
}

void print_user_groups(unsigned user_id, const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap)
{
    const auto &group_ids = user_umap.find(user_id)->second.group_ids(); // Find() instead of [], because user_umap is const, but operator[] not

    if (group_ids.empty())
    {
        std::cout << "You did not join a group yet!\n";
        std::cout << "Go back and join or create a group!\n";
    }
    else
    {
        std::cout << "My groups:\n";
        for (auto id : group_ids)
        {
            std::cout << "(" << id + 1 << ") " << group_umap.find(id)->second.name() << "\n";
        }
    }
}

void print_expenses(unsigned group_id, const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap)
{
    const auto &expenses = group_umap.find(group_id)->second.expenses(); // Find() instead of [], because group_umap is const, but operator[] not
    if (expenses.empty())
    {
        std::cout << "No expenses yet!\n";
    }
    else
    {
        for (const auto &expense : expenses)
        {
            std::cout << "(" << expense.id() + 1 << ") " << user_umap.find(expense.payer_id())->second.name(); // Find() instead of [], because user_umap is const, but operator[] not
            std::cout << " paid " << expense.amount() * 0.01 << " Euro for: ";
            for (auto id : expense.payee_ids())
            {
                std::cout << user_umap.find(id)->second.name();
                if (id != expense.payee_ids().back())
                {
                    std::cout << ", ";
                }
                else
                {
                    std::cout << ".\n";
                }
            }
        }
    }
}