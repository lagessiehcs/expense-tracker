#include "../inc/Group.h"

Group::Group(std::string name)
    : _name(name), _id(counter++)
{
}

unsigned Group::id() const
{
    return _id;
}

std::string Group::name() const
{
    return _name;
}

std::vector<unsigned> Group::member_ids() const
{
    return _member_ids;
}

std::vector<Expense> Group::expenses() const
{
    return _expenses;
}

void Group::edit_expenses(unsigned id, unsigned amount)
{
    _expenses[id].edit(amount);
}

void Group::add_member(const unsigned user_id)
{
    _member_ids.push_back(user_id);
}

void Group::remove_member(unsigned user_id)
{
    auto const it = std::find(_member_ids.begin(), _member_ids.end(), user_id);
    _member_ids.erase(it);
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

    std::vector<unsigned> debtor_ids;
    std::vector<unsigned> creditor_ids;

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

        auto *current_creditor = &user_umap[creditor_ids.back()];
        auto *current_debtor = &user_umap[debtor_ids.back()];

        auto transaction_amount = std::min(current_creditor->balance()[_id], -current_debtor->balance()[_id]);
        std::cout << current_debtor->name() << " owes " << current_creditor->name() << " " << transaction_amount * 0.01 << " Euro.\n";

        current_debtor->update_balance(_id, transaction_amount);
        if (current_debtor->balance()[_id] == 0)
        {
            debtor_ids.pop_back();
        }

        current_creditor->update_balance(_id, -transaction_amount);
        if (current_creditor->balance()[_id] == 0)
        {
            creditor_ids.pop_back();
        }
    }

    std::cout << "The group is now settled!\n";
}

void Group::print_group_members(const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap) const
{
    const auto &member_ids = group_umap.find(_id)->second.member_ids(); // Find() instead of [], because group_umap is const, but operator[] not

    std::cout << "| Group member(s):                                 |\n";
    for (auto member_id : member_ids)
    {

        std::string string = " (" + std::to_string(member_id + 1) + ") " + user_umap.find(member_id)->second.name();
        std::string spaces(50 - string.length(), ' ');
        std::cout << "|" << string << spaces << "|\n";
    }
    std::cout << "|                                                  |\n";
}
