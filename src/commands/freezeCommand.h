#ifndef ___Freeze_COMMAND_H___
#define ___Freeze_COMMAND_H___

#include "string"
#include "command.h"
#include "../chamberCrawler.h"

using namespace std;

class FreezeCommand : public Command {
    private:
        ChamberCrawler* game;

    public:
        FreezeCommand(ChamberCrawler* game);
        string execute() override;
};

#endif