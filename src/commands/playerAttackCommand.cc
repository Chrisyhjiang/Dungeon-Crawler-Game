#include "playerAttackCommand.h"

PlayerATKCommand::PlayerATKCommand(ChamberCrawler* game, string direction) : game(game), direction(direction) {};

string PlayerATKCommand::execute(){
    string actionMsg = "";
    Floor* floor = game->getFloor();
    if(floor){
        Enemy* enemy = floor->canPlayerAttack(direction);
        if(enemy){
            Merchant* m = dynamic_cast<Merchant*>(enemy);
            if (m) {
                Merchant::setHostile(true);
            }
            Player* player = Player::getInstance();
            int HP = enemy->getHP();
            int damage = player->calculateDmgToEnemy(enemy->getDef());
            player->attackEnemy(enemy);
            if(Player::getRace() == TROLL && player->getHP() < player->getDefaultHP()){
                actionMsg += "Player gain HP | ";
            }
            
            if(enemy->getSymbol() == ENEMY_HALFING && HP == enemy->getHP()){
                actionMsg += " player missed attack (HALFING)...";

            }else{
                actionMsg += "PC deals " + std::to_string(damage) + " dmage to Enemy " + string(1, enemy->getSymbol()) 
                        + " (" + to_string(enemy->getHP()) + " HP)";
            }
        }
    }
    return actionMsg;
}