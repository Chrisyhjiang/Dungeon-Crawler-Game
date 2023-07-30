#ifndef ___EXIT_COMMAND_H___
#define ___EXIT_COMMAND_H___

#include "string"
#include "command.h"
#include "../constants.h"

using namespace std;

class ExitCommand : public Command {

    public:
        ExitCommand();
        string execute() override;
};

#endif
