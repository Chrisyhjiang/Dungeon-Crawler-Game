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
                Merchant::setHostile();
            }
            Player* player = Player::getInstance();
            int HP = enemy->getHP();
            int damage = player->calculateDmgToEnemy(enemy->getDef());
            player->attackEnemy(enemy);
            if(Player::getRace() == TROLL && player->getHP() < player->getDefaultHP()){
                actionMsg += "Player gain HP | ";
            }
            
            actionMsg += "Player attacked Enemy " + string(1, enemy->getSymbol()) + " (HP) " + to_string(enemy->getHP());
            
            if(enemy->getSymbol() == ENEMY_HALFING && HP == enemy->getHP()){
                actionMsg += " player missed attack (HALFING)...\n";

            }else{
                actionMsg += " | enemy take damage: " + to_string(damage) + "\n";
            }
        }
    }
    return actionMsg;
}