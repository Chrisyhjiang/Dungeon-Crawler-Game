#include "poisonHPPotion.h"

PoisonHealthPotion::PoisonHealthPotion(Player* player) : ItemDecorator(player){

}

PoisonHealthPotion::~PoisonHealthPotion(){

}

void PoisonHealthPotion::update() {
    target->setHP(target->getHP() - 10);
}
