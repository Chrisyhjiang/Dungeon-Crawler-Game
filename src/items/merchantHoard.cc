#include "merchantHoard.h"


MerchantTreasure::MerchantTreasure(Player* player) : ItemDecorator(player, GOLD_MERCHANT) {}

MerchantTreasure::~MerchantTreasure(){}

void MerchantTreasure::update() {
    Player* player = this->getTarget();
    player->setGold(player->getGold() + 4);
}
