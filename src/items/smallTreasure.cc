#include "smallTreasure.h"

SmallTreasure::SmallTreasure (Player* p) : ItemDecorator(p, GOLD_SMALL) {}

SmallTreasure::~SmallTreasure() {}

void SmallTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + 1);
}
