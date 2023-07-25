#include "goblin.h"

Goblin::Goblin() : Player(125, 25, 25, GOBLIN, 125, 0){
    this->setCellSymbol(SYM_TILE);
   
}

int Goblin::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Goblin::addReward(Enemy* enemy){
    // no reward to add
}