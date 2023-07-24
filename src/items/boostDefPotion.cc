#include "boostDefPotion.h"

BoostDefPotion::BoostDefPotion(Player* p) : ItemDecorator(p) {

}

BoostDefPotion::~BoostDefPotion(){

}

void BoostDefPotion::update() {
    target->setDef(target->getDef() + 5);
}
