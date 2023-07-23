#include "goblin.h"

Goblin::Goblin(){
    this->setHP(125);
    this->setAtk(25);
    this->setDef(25);
    this->setMaxHp(125);
    this->setGold(0);
    this->setRace(SHADE);
}

int Goblin::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Goblin::addReward(Enemy* enemy){
    // no reward to add
}