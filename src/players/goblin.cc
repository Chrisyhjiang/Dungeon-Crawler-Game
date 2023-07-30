#include "goblin.h"

Goblin::Goblin() : Player(110, 15, 20, GOBLIN, 110, 0){}

void Goblin::stealGoldOnEnemySlain(){
    this->setGold(this->getGold() + 5);
}
