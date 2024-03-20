#include "State.h"
#include "../Text.h"
#include "../get_input.h"

//-----INIT----------------------------------------------

class StateInit : public State
{
private:
    unsigned _unsigned_input;

    void entry();

    void during();

    StateName transitions();

public:
    StateInit();
};

//-----START----------------------------------------------

class StateStart : public State
{
private:
    unsigned _unsigned_input;

    void entry();

    void during();

    StateName transitions();

public:
    StateStart();
};

//-----CHOOSE_USER----------------------------------------------

class StateChooseUser : public State
{
private:
    unsigned _unsigned_input;

    void entry();

    void during();

    StateName transitions();

public:
    StateChooseUser();
};

//-----CREATE_USER----------------------------------------------

class StateCreateUser : public State
{
private:
    std::string _string_input;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateCreateUser();
};

//-----USER_HOME----------------------------------------------

class StateUserHome : public State
{
private:
    unsigned _unsigned_input;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateUserHome();
};

//-----CREATE_GROUP----------------------------------------------

class StateCreateGroup : public State
{
private:
    std::string _string_input;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateCreateGroup();
};

//-----CHOOSE_GROUP----------------------------------------------

class StateChooseGroup : public State
{
private:
    unsigned _unsigned_input;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateChooseGroup();
};

//-----JOIN_GROUP----------------------------------------------

class StateJoinGroup : public State
{
private:
    unsigned _unsigned_input;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateJoinGroup();
};
