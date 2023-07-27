#include "normalTreasure.h"

NormalTreasure::NormalTreasure(Player* p) : ItemDecorator(p, GOLD_NORMAL) {}

NormalTreasure::~NormalTreasure() {}

void NormalTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + 2);
}
