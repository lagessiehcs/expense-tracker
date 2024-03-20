#include "../../inc/States/State.h"

State::State(StateName name)
    : _name(name)
{
}

StateName State::run()
{
    _entry();
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
