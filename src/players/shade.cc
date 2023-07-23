#include "shade.h"

Shade::Shade(){
    this->setHP(125);
    this->setAtk(25);
    this->setDef(25);
    this->setMaxHp(125);
    this->setGold(0);
    this->setRace(SHADE);
}

int Shade::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Shade::addReward(Enemy* enemy){
    // no reward to add
}





 