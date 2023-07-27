#include "poisonHPPotion.h"

PoisonHealthPotion::PoisonHealthPotion(Player* player) : ItemDecorator(player, POTION_PH){}

PoisonHealthPotion::~PoisonHealthPotion(){}

void PoisonHealthPotion::update() {
    Player* player = this->getTarget();
    player->setHP(player->getHP() - 10);
}
