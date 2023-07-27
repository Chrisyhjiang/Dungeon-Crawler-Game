#include "dragonTreasure.h"

DragonTreasure::DragonTreasure(Player* p) : ItemDecorator(p, GOLD_DRAGON) {}

DragonTreasure::~DragonTreasure(){}

void DragonTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + 6);
}
