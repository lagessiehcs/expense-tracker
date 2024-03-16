#ifndef GROUP_H
#define GROUP_H

#include <string>
#include <vector>
#include "User.h"
#include "Expense.h"
#include <cmath>

class Settlement;
class Group
{
private:
    int _id;
    std::string _name;
    std::vector<int> _member_ids;
    std::vector<Expense> _expenses;

    // static class member: shared across all class objects
    // inline: so we can initialize it here.
    static inline unsigned counter = 0;

public:
    Group(std::string = "");
    int id() const;
    std::string name() const;
    std::vector<int> member_ids() const;
    std::vector<Expense> expenses() const;
    void edit_expenses(int, int);
    void add_member(const int user_id);
    void add_expense(const Expense &expense);
    void update_member_balance(const Expense &expense, std::vector<User> &user_list);
    void create_settlement(std::vector<User> &user_list);
    void print_group_members(const std::vector<User> &user_list, const std::vector<Group> &group_list) const;
};

#endif
