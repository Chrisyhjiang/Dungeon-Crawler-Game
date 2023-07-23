#include "dragonTreasure.h"

DragonTreasure::DragonTreasure(Player* p) {
    target = p;
}

void DragonTreasure::update() {
    target->setGold(target->getGold() + 6);
}
