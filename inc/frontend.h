#ifndef FRONTEND_H
#define FRONTEND_H

#include "printers.h"
#include <unordered_map>
#include "get_input.h"

void update_terminal(unsigned screen_id, unsigned user_id, unsigned group_id,
                     std::unordered_map<unsigned, User> &user_list, std::unordered_map<unsigned, Group> &group_list);

void get_and_compute_input(unsigned &input_int, float &input_float, std::string &input_str,
                           unsigned &screen_id, unsigned &user_id, unsigned &group_id,
                           std::unordered_map<unsigned, User> &user_list, std::unordered_map<unsigned, Group> &group_list);

#endif