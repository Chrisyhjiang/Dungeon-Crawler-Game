#include "smallTreasure.h"

SmallTreasure::SmallTreasure (Player* p){
    target = p;
}

SmallTreasure::~SmallTreasure() {}

void SmallTreasure::update() {
    target->setGold(target->getGold() + 1);
}
