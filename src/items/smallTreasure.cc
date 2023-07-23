#include "smallTreasure.h"

void SmallTreasure::update() {
    target->setGold(target->getGold() + 1);
}