#include "troll.h"

Troll::Troll() : Player(120, 25, 15, TROLL, 120, 0) {
    this->setCellSymbol(SYM_TILE);
}

int Troll::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Troll::addReward(Enemy* enemy){
    // no reward to add
}
