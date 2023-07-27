#include "restoreHPPotion.h"


RestoreHealthPotion::RestoreHealthPotion(Player* p) : ItemDecorator(p, POTION_RH) {}

RestoreHealthPotion::~RestoreHealthPotion(){}

void RestoreHealthPotion::update() {
    Player* player = this->getTarget();
    player->setHP(player->getHP() + 10);
}
