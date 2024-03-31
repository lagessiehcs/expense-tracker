#ifndef PRINTER_H
#define PRINTER_H

#include "backend.h"
#include <string>

void print_all_users(const std::unordered_map<unsigned, User> &);
void print_all_groups(const std::unordered_map<unsigned, Group> &);

#endif