#include "../../inc/States/State.h"

State::State(StateName name)
    : _name(name)
{
}

void State::enter()
{
    _entry();
}

StateName State::run()
{
    _during();
    return transitions();
}

StateName State::transitions()
{
    // If no transition specified, return the current State
    return _name;
}

StateName State::name()
{
    // always return the current State
    return _name;
}

void State::save_state()
{
    _user_counter = User::counter;
    _group_counter = Group::counter;
    _expense_counter = Expense::counter;
}

void State::load_state()
{
    User::counter = _user_counter;
    Group::counter = _group_counter;
    Expense::counter = _expense_counter;
}

void State::reset_state()
{
    User::counter = 0;
    Group::counter = 0;
    Expense::counter = 0;
}
