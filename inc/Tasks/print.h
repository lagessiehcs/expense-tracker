#ifndef PRINT_H
#define PRINT_H

#include <string>
#include <iostream>
#include <unordered_map>
#include "../Objects/User.h"
#include "../Objects/Group.h"

void print_all_users(const std::unordered_map<unsigned, User> &);
void print_all_groups(const std::unordered_map<unsigned, Group> &);

#endif