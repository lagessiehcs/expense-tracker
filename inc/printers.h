#ifndef PRINTER_H
#define PRINTER_H

#include "backend.h" 

void print_all_users(const std::vector<User> &);
void print_all_groups(const std::vector<Group> &);
void print_user_groups(int, const std::vector<User> &, const std::vector<Group> &);
void print_expenses(int, const std::vector<User> &, const std::vector<Group> &);

#endif