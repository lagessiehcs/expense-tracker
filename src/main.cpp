#include <string>
#include "../inc/States/States.h"
#include <memory>

// states
StateInit s_init;

StateStart s_start;
StateChooseUser s_choose_user;
StateCreateUser s_create_user;

StateUserHome s_user_home;
StateCreateGroup s_create_group;
StateChooseGroup s_choose_group;
StateJoinGroup s_join_group;

StateGroupHome s_group_home;
StateGroupMember s_group_member;
StateAddExpense s_add_expense;
StateCheckExpense s_check_expense;
StateSettlement s_settlement;
StateLeaveGroup s_leave_group;
StateEditExpense s_edit_expense;
StateBalance s_balance;

StateAutoGen s_autogen;

StateExit s_exit;

// array of states
std::vector<std::shared_ptr<State>> states = {std::make_shared<StateInit>(s_init),
                                              std::make_shared<StateStart>(s_start),
                                              std::make_shared<StateChooseUser>(s_choose_user),
                                              std::make_shared<StateCreateUser>(s_create_user),
                                              std::make_shared<StateUserHome>(s_user_home),
                                              std::make_shared<StateCreateGroup>(s_create_group),
                                              std::make_shared<StateChooseGroup>(s_choose_group),
                                              std::make_shared<StateJoinGroup>(s_join_group),
                                              std::make_shared<StateGroupHome>(s_group_home),
                                              std::make_shared<StateGroupMember>(s_group_member),
                                              std::make_shared<StateAddExpense>(s_add_expense),
                                              std::make_shared<StateCheckExpense>(s_check_expense),
                                              std::make_shared<StateSettlement>(s_settlement),
                                              std::make_shared<StateLeaveGroup>(s_leave_group),
                                              std::make_shared<StateEditExpense>(s_edit_expense),
                                              std::make_shared<StateBalance>(s_balance),
                                              std::make_shared<StateAutoGen>(s_autogen),
                                              std::make_shared<StateExit>(s_exit)};

// current state
State *currentState;

State *getState(StateName state_name)
{
    for (auto &state : states)
    {
        if (state->name() == state_name)
        {
            return state.get();
        }
    }
    return nullptr;
}

int main()
{
    currentState = states[0].get();
    currentState->enter();
    while (true)
    {
        StateName nextState = currentState->run();
        if (currentState->name() == s_exit.name() and nextState == s_exit.name())
        {
            return 0;
        }
        currentState = getState(nextState);
        currentState->enter();
    }
}
