
#include "../inc/printers.h"

void print_all_users(const std::vector<User> &user_list){

    if (user_list.empty()){
        std::cout << "No users yet! Go back and create a user!\n";
    }else{
        std::cout << "Users:\n";
        for (const auto& user: user_list){
            std::cout << "(" << user.id() + 1 << ") " << user.name() << "\n";
            }
    } 
}

void print_all_groups(const std::vector<Group> &group_list){

    if (group_list.empty()){
        std::cout << "No groups yet! Go back and create a group!\n";
    }else{
        std::cout << "Groups: \n";
        for (const auto& group: group_list){
            std::cout << "(" << group.id() +1 << ") " << group.name() << "\n";
            }
    }
}

void print_user_groups(int user_id,const std::vector<User>& user_list,const std::vector<Group> &group_list){
    if (user_list[user_id].group_ids().empty()){
        std::cout << "You did not join a group yet!\n";
        std::cout << "Go back and join or create a group!\n";
    }else{
        std::cout << "My groups:\n";
        for (auto id: user_list[user_id].group_ids()){
            std::cout << "(" << id+1 << ") " << group_list[id].name() << "\n";
        } 
    }
}


void print_expenses(int group_id,const std::vector<User> &user_list,const std::vector<Group> &group_list){
    if (group_list[group_id].expenses().empty()){
        std::cout << "No expenses yet!\n";
    }else{
        for (const auto& expense: group_list[group_id].expenses()){
            std::cout << "(" << expense.id()+1 << ") " << user_list[expense.payer_id()].name();
            std::cout << " paid " << expense.amount() * 0.01 << " Euro for: ";
            for (auto id: expense.payee_ids()){
                std::cout << user_list[id].name();
                if (id != expense.payee_ids().back()){
                    std::cout << ", ";
                }else{
                    std::cout << ".\n";
                }
            }
        }
    }
}