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

// // Use Potion Command
// class UsePotionCommand : public Command {
// private:
//     PlayerCharacter& player;
//     Direction direction;

// public:
//     UsePotionCommand(PlayerCharacter& player, Direction direction)
//         : player(player), direction(direction) {}

//     void execute() override {
//         player.usePotion(direction);
//     }
// };

// // Attack Command
// class AttackCommand : public Command {
// private:
//     PlayerCharacter& player;
//     Direction direction;

// public:
//     AttackCommand(PlayerCharacter& player, Direction direction)
//         : player(player), direction(direction) {}

//     void execute() override {
//         player.attack(direction);
//     }
// };

// // Select Race Command
// class SelectRaceCommand : public Command {
// private:
//     PlayerCharacter& player;
//     Race race;

// public:
//     SelectRaceCommand(PlayerCharacter& player, Race race)
//         : player(player), race(race) {}

//     void execute() override {
//         player.selectRace(race);
//     }
// };

// // Restart Game Command
// class RestartGameCommand : public Command {
// private:
//     PlayerCharacter& player;

// public:
//     RestartGameCommand(PlayerCharacter& player)
//         : player(player) {}

//     void execute() override {
//         player.restartGame();
//     }
// };
