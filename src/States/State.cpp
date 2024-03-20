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
