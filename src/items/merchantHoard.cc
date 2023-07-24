#include "merchantHoard.h"


MerchantTreasure::MerchantTreasure(Player* player) : ItemDecorator(player) {

}

MerchantTreasure::~MerchantTreasure(){

}

void MerchantTreasure::update() {
    target->setGold(target->getGold() + 4);
}
