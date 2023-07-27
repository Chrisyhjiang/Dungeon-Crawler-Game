#include "treasure.h"

Treasure::Treasure (Player* p, string name, int gold) : ItemDecorator(p, name), gold(gold) {}

Treasure::~Treasure(){}

int Treasure::getGold(){
    return gold;
}

void Treasure::setGold(int g){
    gold = g;
}