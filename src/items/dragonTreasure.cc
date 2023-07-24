#include "dragonTreasure.h"

DragonTreasure::DragonTreasure(Player* p) : ItemDecorator(p) {
    target = p;
}

DragonTreasure::~DragonTreasure(){
}

void DragonTreasure::update() {
    target->setGold(target->getGold() + 6);
}
