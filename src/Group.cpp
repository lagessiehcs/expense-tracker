#include "../inc/Group.h"

Group::Group(std::string name)
    : _name(name), _id(counter++)
{
}

int Group::id() const
{
    return _id;
}

std::string Group::name() const
{
    return _name;
}

std::vector<int> Group::member_ids() const
{
    return _member_ids;
}

std::vector<Expense> Group::expenses() const
{
    return _expenses;
}

void Group::edit_expenses(int id, int amount)
{
    _expenses[id].edit(amount);
}

void Group::add_member(const int user_id)
{
    _member_ids.push_back(user_id);
}

void Group::add_expense(const Expense &expense)
{
    _expenses.push_back(expense);
}

void Group::update_member_balance(const Expense &expense, std::unordered_map<unsigned, User> &user_umap)
{

    auto payee_number = expense.payee_ids().size();
    auto individual_amount = expense.amount() / payee_number;
    for (auto member_id : _member_ids)
    {
        if (member_id == expense.payer_id())
        {
            user_umap[member_id].update_balance(_id, individual_amount * payee_number);
        }
        for (auto payee_id : expense.payee_ids())
        {
            if (member_id == payee_id)
            {
                user_umap[member_id].update_balance(_id, -individual_amount);
            }
        }
    }
}

void Group::create_settlement(std::unordered_map<unsigned, User> &user_umap)
{

    std::vector<int> debtor_ids;
    std::vector<int> creditor_ids;

    for (auto member_id : _member_ids)
    {
        auto user_balance = user_umap[member_id].balance()[_id];
        if (user_balance < 0)
        {
            debtor_ids.push_back(member_id);
        }
        else if (user_balance > 0)
        {
            creditor_ids.push_back(member_id);
        }
    }

    while (not debtor_ids.empty())
    {

        auto &creditor = user_umap[creditor_ids.back()];
        auto &debtor = user_umap[debtor_ids.back()];

        int transaction_amount = -debtor.balance()[_id];
        std::cout << debtor.name() << " owes " << creditor.name() << " " << transaction_amount * 0.01 << " Euro.\n";

        debtor.update_balance(_id, transaction_amount);
        debtor_ids.pop_back();

        creditor.update_balance(_id, -transaction_amount);
        if (creditor.balance()[_id] <= 0)
        {
            creditor_ids.pop_back();
            {
                if (creditor.balance()[_id] < 0)
                {
                    debtor_ids.push_back(creditor.id());
                }
            }
        }
    }

    std::cout << "The group is now settled!\n";
}

void Group::print_group_members(const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap) const
{
    const auto &member_ids = group_umap.find(_id)->second.member_ids();
    if (group_umap.find(_id)->second.member_ids().empty())
    {
        std::cout << "This group is empty!\n";
    }
    else
    {
        std::cout << "Group member(s):\n";
        for (auto member_id : group_umap.find(_id)->second.member_ids())
        {
            std::cout << "(" << member_id + 1 << ") " << user_umap.find(member_id)->second.name() << "\n";
        }
    }
}
