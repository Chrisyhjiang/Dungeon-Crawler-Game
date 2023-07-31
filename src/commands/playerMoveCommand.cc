#include "playerMoveCommand.h"

PlayerMoveCommand::PlayerMoveCommand(ChamberCrawler* game, string direction) : game(game), direction(direction) {};

string PlayerMoveCommand::execute(){
    Floor* floor = game->getFloor();
    string s = "";
    if(floor){
        s = floor->movePlayer(direction);
    }
    return s;
}

