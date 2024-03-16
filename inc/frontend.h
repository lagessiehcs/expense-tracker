#ifndef FRONTEND_H
#define FRONTEND_H

#include "printers.h"

void update_terminal(int screen_id ,int user_id, int group_id,
                     std::vector<User>& user_list, std::vector<Group>& group_list);

void get_and_compute_input(int& input_int, float& input_float, std::string& input_str, 
               int& screen_id, int& user_id, int& group_id, 
               std::vector<User>& user_list, std::vector<Group>& group_list);


#endif