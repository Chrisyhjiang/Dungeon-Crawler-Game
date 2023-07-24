#include "smallTreasure.h"

SmallTreasure::SmallTreasure (Player* p) : ItemDecorator(p) {
    target = p;
}

SmallTreasure::~SmallTreasure() {}

void SmallTreasure::update() {
    target->setGold(target->getGold() + 1);
}
