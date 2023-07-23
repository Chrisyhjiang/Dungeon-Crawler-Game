#include "normalTreasure.h"

NormalTreasure::NormalTreasure(Player* p) {
    target = p;
}


void NormalTreasure::update() {
    target->setGold(target->getGold() + 2);
}
