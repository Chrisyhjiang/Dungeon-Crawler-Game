#include "treasureHoard.h"

TreasureHoard::TreasureHoard(int gold) : gold(gold){}

TreasureHoard::~TreasureHoard(){}

int TreasureHoard::getGoldAmount(){
    return gold;
}

void TreasureHoard::setGoldAmount(int amt){
    gold = amt;
}