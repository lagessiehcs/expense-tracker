#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include "User.h"
#include "Expense.h"
#include <cmath>
#include <unordered_map>
#include <algorithm>

class User;
class Group
{
private:
    const unsigned _id;
    std::string _name;
    std::vector<unsigned> _member_ids;
    std::vector<Expense> _expenses;
    unsigned _expense_counter{0};

public:
    Group(std::string = "");
    unsigned id() const;
    std::string name() const;
    std::vector<unsigned> member_ids() const;
    std::vector<Expense> expenses() const;
    void edit_expenses(unsigned, unsigned);
    void add_member(const unsigned user_id);
    void remove_member(unsigned user_id);
    void add_expense(unsigned amount, unsigned payer_id, std::vector<unsigned> &payee_ids);
    void update_member_balance(unsigned amount, unsigned payer_id, std::vector<unsigned> &payee_ids, std::unordered_map<unsigned, User> &user_umap);
    void print_expenses(const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap);
    void print_group_members(const std::unordered_map<unsigned, User> &user_umap, const std::unordered_map<unsigned, Group> &group_umap) const;
    void create_settlement(std::unordered_map<unsigned, User> &user_umap);

    // static class member: shared across all class objects
    // inline: so we can initialize it here.
    static inline unsigned counter{0};
};

#endif
