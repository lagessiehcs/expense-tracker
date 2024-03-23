#ifndef BACKEND_H
#define BACKEND_H

#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include "User.h"
#include "Group.h"

User add_user(std::string, std::unordered_map<unsigned, User> &);
void add_user_to_group(User &, Group &);
void remove_user_from_group(User &user, Group &group);
unsigned add_group(std::string, std::unordered_map<unsigned, Group> &);
Expense add_expense_to_group(unsigned amount, unsigned payer_id, std::vector<unsigned> payee_ids, Group &group, std::unordered_map<unsigned, User> &user_list);
void edit_expense(Group &, unsigned, unsigned);

#endif