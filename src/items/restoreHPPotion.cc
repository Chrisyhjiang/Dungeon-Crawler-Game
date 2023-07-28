#include "restoreHPPotion.h"


RestoreHealthPotion::RestoreHealthPotion(Player* p, double magnify) : Potion (p, POTION_RH, magnify) {}

RestoreHealthPotion::~RestoreHealthPotion(){}

void RestoreHealthPotion::update() {
    Player* player = this->getTarget();
    player->setHP(player->getHP() + 10 * this->getMagnify());
}
