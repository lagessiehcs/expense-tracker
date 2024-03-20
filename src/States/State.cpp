#include "../../inc/States/State.h"

State::State(StateName name)
    : _name(name)
{
}

StateName State::run()
{
    during();
    return transitions();
}

void State::enter()
{
    this->entry();
}

StateName State::transitions()
{
    // If no transition specified, return the current State
    return _name;
}