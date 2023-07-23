#include "woundDef.h"

void WoundDefPotion::update() {
    target->setDef(target->getDef() - 5);
}
