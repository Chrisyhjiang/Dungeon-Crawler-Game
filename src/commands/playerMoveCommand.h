#ifndef ___PlAYERMOVECOMMAND_H___
#define ___PLAYERMOVECOMMAND_H___

#include "string"
#include "command.h"
#include "../chamberCrawler.h"

using namespace std;

class PlayerMoveCommand : public Command {
    private:
        ChamberCrawler* game;
        string direction;

    public:
        PlayerMoveCommand(ChamberCrawler* game, string direction);
        string execute() override;
};

#endif
