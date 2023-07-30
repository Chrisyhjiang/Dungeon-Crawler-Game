#include "playerUsePotion.h"

PlayerUsePotionCommand::PlayerUsePotionCommand(ChamberCrawler* game, string direction) : game(game), direction(direction) {};

string PlayerUsePotionCommand::execute(){
    string actionMsg = "";
    Floor* floor = game->getFloor();
    if(floor){
        ItemDecorator* potion = floor->canPlayerTakePotion(direction);
        if(potion){  
            potion->update();
            actionMsg = "PC uses: " + potion->getName() + ".\n";
        }
    }
    return actionMsg;
}
