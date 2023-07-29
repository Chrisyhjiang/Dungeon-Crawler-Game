#include "poisonHPPotion.h"

PoisonHealthPotion::PoisonHealthPotion(Player* player, double magnify) : Potion (player, POTION_PH, magnify){}

PoisonHealthPotion::~PoisonHealthPotion(){}

void PoisonHealthPotion::update() {
    Player* player = this->getTarget();
    player->setHP(player->getHP() - 10 * this->getMagnify());
}
