#include "woundDefPotion.h"

WoundDefPotion::WoundDefPotion(Player* p, double magnify) : Potion (p, POTION_WD, magnify) {}

WoundDefPotion::~WoundDefPotion(){} 

void WoundDefPotion::update() {
    Player* target = this->getTarget();
    int def = std::max(0, (int)(target->getDef() - 5 * this->getMagnify()));
    target->setDef(def);
}
