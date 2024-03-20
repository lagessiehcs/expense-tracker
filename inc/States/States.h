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

//-----GROUP_HOME----------------------------------------------

class StateGroupHome : public State
{
private:
    unsigned _unsigned_input;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateGroupHome();
};

//-----GROUP_MEMBER----------------------------------------------

class StateGroupMember : public State
{
private:
    unsigned _unsigned_input;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateGroupMember();
};

//-----ADD_EXPENSE----------------------------------------------

class StateAddExpense : public State
{
private:
    float _float_input;
    unsigned _unsigned_input;

    std::vector<unsigned> _payee_ids;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateAddExpense();
};

//-----CHECK_EXPENSE----------------------------------------------

class StateCheckExpense : public State
{
private:
    float _float_input;
    unsigned _unsigned_input;

    std::vector<unsigned> _payee_ids;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateCheckExpense();
};

//-----SETTLEMENT----------------------------------------------

class StateSettlement : public State
{
private:
    float _float_input;
    unsigned _unsigned_input;

    std::vector<unsigned> _payee_ids;

    std::unordered_map<unsigned, User> _user_umap;

    void entry();

    void during();

    StateName transitions();

public:
    StateSettlement();
};