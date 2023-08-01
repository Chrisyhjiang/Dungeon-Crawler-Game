#include "restartCommand.h"

RestartCommand::RestartCommand(ChamberCrawler* game) : game(game){}

string RestartCommand::execute(){
   game->restartGame();
   return "game restarted...";
}
