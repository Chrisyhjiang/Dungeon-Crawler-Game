#include "boostAtkPotion.h"

BoostAtkPotion::BoostAtkPotion(Player* p) : ItemDecorator(p) {

}

BoostAtkPotion::~BoostAtkPotion(){

}

void BoostAtkPotion::update() {
    target->setAtk(target->getAtk() + 5);
}
