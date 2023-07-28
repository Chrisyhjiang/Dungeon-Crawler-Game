#include "goblin.h"

Goblin::Goblin() : Player(125, 25, 25, GOBLIN, 125, 0){
  //  this->setCellSymbol(SYM_TILE);
}

// int Goblin::calculateDmgToEnemy(){
//     return this->getAtk();
// }

void Goblin::addReward(Enemy* enemy){
    // no reward to add
}

void Goblin::attackEnemy(Enemy* en) {
  Player::attackEnemy(en);
  this->setGold(this->getGold() + 5);
}
