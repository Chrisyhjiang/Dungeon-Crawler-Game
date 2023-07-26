#include "shade.h"

Shade::Shade() : Player(125, 25, 25, SHADE, 125, 0){
   // this->setCellSymbol(SYM_TILE);
}

int Shade::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Shade::addReward(Enemy* enemy){
    // no reward to add
}





 