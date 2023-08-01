#include "freezeCommand.h"

FreezeCommand::FreezeCommand(ChamberCrawler* game) : game(game){}

string FreezeCommand::execute(){
    game->setFreezeEnemy(!game->getFreezeEnemy());
    return CMD_FREEZE + "\n";
}