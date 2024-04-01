#ifndef MANAGE_USER_GROUP_H
#define MANAGE_USER_GROUP_H

#include <unordered_map>
#include "../Objects/User.h"
#include "../Objects/Group.h"
#include <algorithm>

User add_user(std::string, std::unordered_map<unsigned, User> &);
void add_user_to_group(User &, Group &);
void remove_user_from_group(User &user, Group &group);
unsigned add_group(std::string, std::unordered_map<unsigned, Group> &);
void add_expense_to_group(unsigned amount, unsigned payer_id, std::vector<unsigned> payee_ids, Group &group, std::unordered_map<unsigned, User> &user_list);

#endif