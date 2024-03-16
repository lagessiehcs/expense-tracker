#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>

class User
{

private:
    std::string _name;
    int _id;
    std::map<int, int> _balance;
    std::vector<int> _group_ids;

    // static class member: shared across all class objects
    // inline: so we can initialize it here.
    static inline unsigned counter = 0;

public:
    User(std::string name = "");
    std::string name() const;
    int id() const;
    std::vector<int> group_ids() const;
    void join_group(int group_id);
    void update_balance(int group_id, int balance);
    std::map<int, int> balance();
    void show_balance(int group_id);
};

#endif