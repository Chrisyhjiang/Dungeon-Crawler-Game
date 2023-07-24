#include "normalTreasure.h"

NormalTreasure::NormalTreasure(Player* p) : ItemDecorator(p) {
   // target = p;
}

NormalTreasure::~NormalTreasure() {
   
}

void NormalTreasure::update() {
    target->setGold(target->getGold() + 2);
}
