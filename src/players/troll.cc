#include "troll.h"

Troll::Troll(){
    this->setHP(120);
    this->setAtk(25);
    this->setDef(15);
    this->setMaxHp(120);
    this->setGold(0);
    this->setRace(TROLL);
}

int Troll::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Troll::addReward(Enemy* enemy){
    // no reward to add
}
