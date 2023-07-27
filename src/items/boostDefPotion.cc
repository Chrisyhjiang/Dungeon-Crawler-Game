#include "boostDefPotion.h"

BoostDefPotion::BoostDefPotion(Player* p) : ItemDecorator(p, POTION_BD) {}

BoostDefPotion::~BoostDefPotion(){}

void BoostDefPotion::update() {
    Player* player = this->getTarget();
    player->setDef(player->getDef() + 5);
}
