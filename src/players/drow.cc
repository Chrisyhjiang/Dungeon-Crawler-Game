#include "drow.h"

Drow::Drow(){
    this->setHP(150);
    this->setAtk(25);
    this->setDef(15);
    this->setMaxHp(150);
    this->setGold(0);
    this->setRace(DROW);
}

int Drow::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Drow::addReward(Enemy* enemy){
    // no reward to add
}