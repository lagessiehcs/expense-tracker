#include "../inc/User.h"
#include <cmath>


User::User(std::string name, int id) 
: _name(name), _id(id) {

}

std::string User::name() const{    
    return _name;
}

int User::id() const{
    return _id;
}
   
std::vector<int> User::group_ids() const{
    return _group_ids;
}

void User::join_group(int group_id){
    _group_ids.push_back(group_id);
}

void User::update_balance(int group_id, int balance){
    _balance[group_id] += balance;
}

std::map<int,int> User::balance() {
    return _balance;
}

void User::show_balance(int group_id) {
    std::cout << "Your balance:\n";
    if (_balance[group_id] == 0) {
        std::cout << "You dont get nor owe any money.\n";
    } else if (_balance[group_id] > 0) {
        std::cout << "You get " << _balance[group_id]*0.01 << " Euro.\n";
    } else {
        std::cout << "You owe " << -_balance[group_id]*0.01 << " Euro.\n";
    }
    
}

