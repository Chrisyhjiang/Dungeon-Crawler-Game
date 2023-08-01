#include "commandInput.h"

CommandInput::CommandInput(string action, string direction, bool valid) : action(action), direction(direction), valid(valid) {}

CommandInput::~CommandInput(){};

string CommandInput::getAction(){
    return action;
}

void CommandInput::setAction(string action){
    this->action = action;
}

string CommandInput::getDirection(){
    return direction;
}

void CommandInput::setIsValid(bool v){
    valid = v;
}

bool CommandInput::getIsValid(){
    return valid;
}

void CommandInput::setDirection(string direction){
    this->direction = direction;
}
