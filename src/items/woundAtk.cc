#include "woundAtk.h"

void WoundAtkPotion::update() {
    target->setAtk(target->getAtk() - 5);
}

