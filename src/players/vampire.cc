#include <limits.h>
#include "vampire.h"


Vampire::Vampire(){
    this->setHP(50);
    this->setAtk(25);
    this->setDef(25);
    this->setMaxHp(INT_MAX);
    this->setGold(0);
    this->setRace(SHADE);
}

int Vampire::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Vampire::addReward(Enemy* enemy){
    // no reward to add
}