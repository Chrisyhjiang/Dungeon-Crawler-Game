#include "boostAtkPotion.h"

BoostAtkPotion::BoostAtkPotion(Player* p) : ItemDecorator(p, POTION_BA) {}

BoostAtkPotion::~BoostAtkPotion(){}

void BoostAtkPotion::update() {
    Player* player = this->getTarget();
    player->setAtk(player->getAtk() + 5);
}
