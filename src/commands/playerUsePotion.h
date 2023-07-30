#ifndef ___PlAYER_USE_POTION_COMMAND_H___
#define ___PLAYER_USE_POTION_COMMAND_H___

#include "string"
#include "command.h"
#include "../chamberCrawler.h"

using namespace std;

class PlayerUsePotionCommand : public Command {
    private:
        ChamberCrawler* game;
        string direction;

    public:
        PlayerUsePotionCommand(ChamberCrawler* game, string direction);
        string execute() override;
};

#endif