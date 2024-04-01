#include "../../inc/Objects/Group.h"

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
    auto payee_ids = expense.payee_ids();
    auto payer_id = expense.payer_id();
    auto expense_amount = expense.amount();

    auto individual_amount = expense_amount / payee_ids.size();

    user_umap[payer_id].update_balance(_id, expense_amount);
    for (auto payee_id : payee_ids)
    {
        user_umap[payee_id].update_balance(_id, -individual_amount);
    }
}

void Group::print_expenses(const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap)
{
    const auto &expenses = group_umap.find(_id)->second.expenses(); // Find() instead of [], because group_umap is const, but operator[] not
    if (expenses.empty())
    {
        std::cout << "| No expenses yet!                                 |\n";
        std::cout << "|                                                  |\n";
    }
    else
    {
        for (const auto &expense : expenses)
        {
            auto number = std::to_string(expense.id() + 1);
            std::string string = " (" + number + ") " + user_umap.find(expense.payer_id())->second.name() + " paid " + std::to_string((int)(expense.amount() * 0.01)) + " Euro for: ";
            std::string spaces(50 - string.length(), ' ');
            std::cout << "|" << string << spaces << "|\n";

            string.assign(4 + number.length(), ' ');

            for (auto id : expense.payee_ids())
            {
                auto payee_name = user_umap.find(id)->second.name();
                if (string.length() + payee_name.length() + 2 < 50) // 2 for ", " or "."
                {
                    string += payee_name;
                }
                else
                {
                    spaces.assign(50 - string.length(), ' ');
                    std::cout << "|" << string << spaces << "|\n";
                    string.assign(4 + number.length(), ' ');
                    string += payee_name;
                }

                if (id != expense.payee_ids().back())
                {
                    string += ", ";
                }
                else
                {
                    string += ".";
                }
            }
            spaces.assign(50 - string.length(), ' ');
            std::cout << "|" << string << spaces << "|\n";
            std::cout << "|                                                  |\n";
        }
    }
    if (!expenses.empty())
    {
        std::cout << "| (Input the number before each expense to edit)   |\n";
        std::cout << "|                                                  |\n";
    }

    std::cout << "| (0) Back                                         |\n";
    std::cout << "*--------------------------------------------------*\n";
}

void Group::print_group_members(const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap) const
{
    const auto &member_ids = group_umap.find(_id)->second.member_ids(); // Find() instead of [], because group_umap is const, but operator[] !

    std::cout << "| Group member(s):                                 |\n";
    for (auto member_id : member_ids)
    {

        std::string string = " (" + std::to_string(member_id + 1) + ") " + user_umap.find(member_id)->second.name();
        std::string spaces(50 - string.length(), ' ');
        std::cout << "|" << string << spaces << "|\n";
    }
    std::cout << "|                                                  |\n";
}

void Group::create_settlement(std::unordered_map<unsigned, User> &user_umap)
{
    int transaction_amount{};
    std::unordered_map<std::string, int> debtor_balances;
    std::unordered_map<std::string, int> creditor_balances;

    for (auto id : _member_ids)
    {
        auto balance = user_umap[id].balance()[_id];
        auto name = user_umap[id].name();

        if (balance < 0)
        {
            debtor_balances[name] = balance;
        }
        else if (balance > 0)
        {
            creditor_balances[name] = balance;
        }
    }

    while (!debtor_balances.empty())
    {
        auto creditor_balance_it = creditor_balances.begin(); // iterator to the first balance
        auto debtor_balance_it = debtor_balances.begin();     // iterator to the first balance

        auto creditor_name = creditor_balance_it->first;
        auto debtor_name = debtor_balance_it->first;

        // find if there is a debtor that owes the same amount as the current creditor gets
        auto it = std::find_if(debtor_balances.begin(), debtor_balances.end(),
                               [&creditor_balance_it](std::pair<std::string, int> pair)
                               { return creditor_balance_it->second == -pair.second; });

        if (it != debtor_balances.end())
        {
            transaction_amount = creditor_balance_it->second;
            debtor_name = it->first;
            std::cout << debtor_name << " owes " << creditor_name << " " << transaction_amount * 0.01 << " Euro.\n";
            debtor_balances.erase(it);
            creditor_balances.erase(creditor_balance_it);
            continue;
        }
        else
        {
            // find if there is a creditor that gets the same amount as the current creditor owes
            it = std::find_if(creditor_balances.begin(), creditor_balances.end(),
                              [&debtor_balance_it](std::pair<std::string, int> pair)
                              { return debtor_balance_it->second == -pair.second; });

            if (it != creditor_balances.end())
            {
                transaction_amount = it->second;
                creditor_name = it->first;
                std::cout << debtor_name << " owes " << creditor_name << " " << transaction_amount * 0.01 << " Euro.\n";
                creditor_balances.erase(it);
                debtor_balances.erase(debtor_balance_it);
                continue;
            }
        }

        if (creditor_balance_it->second > -debtor_balance_it->second)
        {
            creditor_balance_it->second += debtor_balance_it->second;
            transaction_amount = -debtor_balance_it->second;
            debtor_balances.erase(debtor_balance_it);
        }
        else if (creditor_balance_it->second < -debtor_balance_it->second)
        {
            debtor_balance_it->second += creditor_balance_it->second;
            transaction_amount = creditor_balance_it->second;
            creditor_balances.erase(creditor_balance_it);
        }

        std::cout << debtor_name << " owes " << creditor_name << " " << transaction_amount * 0.01 << " Euro.\n";
    }
    for (auto member_id : _member_ids)
    {
        if (user_umap[member_id].balance()[_id] != 0)
        {
            user_umap[member_id].set_balance(_id, 0);
        }
    }
    std::cout << "The group is now settled!\n";
}
