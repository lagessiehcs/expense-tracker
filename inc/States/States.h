#include "State.h"
#include "../Text.h"
#include "../Tasks/get_input.h"
#include "../Tasks/auto_generate.h"
#include <chrono>

//-----INIT----------------------------------------------

class StateInit : public State
{
private:
    std::string _string_input;

    const std::vector<std::string> _valid_input = {"1", "2", "00"};

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateInit();
};

//-----START----------------------------------------------

class StateStart : public State
{
private:
    std::string _string_input;

    const std::vector<std::string> _valid_input = {"1", "2", "0", "00"};

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateStart();
};

//-----LOGIN----------------------------------------------

class StateLogin : public State
{
private:
    std::string _string_input;

    std::vector<std::string> _valid_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateLogin();
};

//-----NEW_USER----------------------------------------------

class StateNewUser : public State
{
private:
    std::string _string_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateNewUser();
};

//-----USER_HOME----------------------------------------------

class StateUserHome : public State
{
private:
    std::string _string_input;

    const std::vector<std::string> _valid_input = {"1", "2", "3", "0"};

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateUserHome();
};

//-----NEW_GROUP----------------------------------------------

class StateNewGroup : public State
{
private:
    std::string _string_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateNewGroup();
};

//-----CHOOSE_GROUP----------------------------------------------

class StateChooseGroup : public State
{
private:
    std::string _string_input;

    std::vector<std::string> _valid_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateChooseGroup();
};

//-----JOIN_GROUP----------------------------------------------

class StateJoinGroup : public State
{
private:
    std::string _string_input;

    std::vector<std::string> _valid_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateJoinGroup();
};

//-----GROUP_HOME----------------------------------------------

class StateGroupHome : public State
{
private:
    std::string _string_input;

    const std::vector<std::string> _valid_input = {"0", "1", "2", "3", "4", "5", "6"};

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateGroupHome();
};

//-----GROUP_MEMBER----------------------------------------------

class StateGroupMember : public State
{
private:
    unsigned _unsigned_input;

    std::string _string_input;

    const std::vector<std::string> _valid_input = {"0"};

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateGroupMember();
};

//-----ADD_EXPENSE----------------------------------------------

class StateAddExpense : public State
{
private:
    float _float_input;

    std::string _string_input;

    std::vector<std::string> _valid_input;

    bool expense_added{false};

    std::vector<unsigned> _payee_ids;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateAddExpense();
};

//-----CHECK_EXPENSE----------------------------------------------

class StateCheckExpense : public State
{
private:
    std::string _string_input;

    std::vector<std::string> _valid_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateCheckExpense();
};

//-----SETTLEMENT----------------------------------------------

class StateSettlement : public State
{
private:
    std::string _string_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateSettlement();
};

//-----LEAVE_GROUP----------------------------------------------

class StateLeaveGroup : public State
{
private:
    std::string _string_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateLeaveGroup();
};

//-----EDIT_EXPENSE----------------------------------------------

class StateEditExpense : public State
{
private:
    std::string _string_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateEditExpense();
};

//-----BALANCE----------------------------------------------

class StateBalance : public State
{
private:
    std::string _string_input;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateBalance();
};

//-----AUTO_GEN----------------------------------------------

class StateAutoGen : public State
{
private:
    std::string _path;

    std::string _string_input;

    const std::vector<std::string> _valid_input = {"0", "00"};

    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;

    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateAutoGen();
};

//-----EXIT----------------------------------------------

class StateExit : public State
{
private:
    void _entry() override;

    void _during() override;

    StateName transitions();

public:
    StateExit();
};