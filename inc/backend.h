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
unsigned add_group(std::string, std::unordered_map<unsigned, Group> &);
Expense add_expense_to_group(int amount, int payer_id, std::vector<int> payee_ids, Group &group, std::unordered_map<unsigned, User> &user_list);
void edit_expense(Group &, int, int);

#endif