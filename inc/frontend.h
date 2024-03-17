#ifndef FRONTEND_H
#define FRONTEND_H

#include "printers.h"
#include <unordered_map>

void update_terminal(int screen_id, int user_id, int group_id,
                     std::unordered_map<unsigned, User> &user_list, std::unordered_map<unsigned, Group> &group_list);

void get_and_compute_input(int &input_int, float &input_float, std::string &input_str,
                           int &screen_id, int &user_id, int &group_id,
                           std::unordered_map<unsigned, User> &user_list, std::unordered_map<unsigned, Group> &group_list);

#endif