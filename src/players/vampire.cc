#include <limits.h>
#include "vampire.h"


Vampire::Vampire() : Player(50, 25, 25, VAMPIRE, INT_MAX, 0) {
    this->setCellSymbol(SYM_TILE);
}

int Vampire::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Vampire::addReward(Enemy* enemy){
    // no reward to add
}