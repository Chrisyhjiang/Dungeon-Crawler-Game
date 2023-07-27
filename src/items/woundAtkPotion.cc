#include "woundAtkPotion.h"


WoundAtkPotion::WoundAtkPotion(Player* p) : ItemDecorator(p, POTION_WA) {}

WoundAtkPotion::~WoundAtkPotion(){}

void WoundAtkPotion::update() {
    Player* target = this->getTarget();
    target->setAtk(target->getAtk() - 5);
}

