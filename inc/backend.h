#ifndef BACKEND_H
#define BACKEND_H

#include <vector>
#include <string>
#include <iostream>
#include "User.h"
#include "Group.h"

User add_user(std::string, std::vector<User> &);
void add_user_to_group(User &, Group &);
Group add_group(std::string, std::vector<Group> &);
Expense add_expense_to_group(int amount, int payer_id, std::vector<int> payee_ids, Group &group, std::vector<User> &user_list);
void edit_expense(Group &, int, int);

#endif