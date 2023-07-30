#ifndef ___RESTART_COMMAND_H___
#define ___RESTART_COMMAND_H___

#include "string"
#include "command.h"
#include "../chamberCrawler.h"

using namespace std;

class RestartCommand : public Command {
    private:
        ChamberCrawler* game;

    public:
        RestartCommand(ChamberCrawler* game);
        string execute() override;
};

#endif

