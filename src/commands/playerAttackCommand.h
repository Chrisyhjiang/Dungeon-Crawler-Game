#ifndef ___PlAYER_ATK_COMMAND_H___
#define ___PLAYER_ATK_COMMAND_H___

#include "string"
#include "command.h"
#include "../chamberCrawler.h"

using namespace std;

class PlayerATKCommand : public Command {
    private:
        ChamberCrawler* game;
        string direction;

    public:
        PlayerATKCommand(ChamberCrawler* game, string direction);
        string execute() override;
};

#endif
