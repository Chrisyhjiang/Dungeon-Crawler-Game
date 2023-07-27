#include "woundDefPotion.h"

WoundDefPotion::WoundDefPotion(Player* p) : ItemDecorator(p, POTION_WD) {}

WoundDefPotion::~WoundDefPotion(){} 

void WoundDefPotion::update() {
    Player* target = this->getTarget();
    target->setDef(target->getDef() - 5);
}
