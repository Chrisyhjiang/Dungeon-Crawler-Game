#include "merchant.h"

bool Merchant::hostile = false;

Merchant::Merchant(string race) : Enemy(30, 70, 5, race, ENEMY_MERCHANT) {};
Merchant::Merchant(int hp, int atk, int def, string race, char symbol) : Enemy(hp, atk, def, race, symbol){}

Merchant::~Merchant(){}


 bool Merchant::isHostile(){
    return hostile;
 }

void  Merchant::setHostile(bool b){
    hostile = b;
}

bool Merchant::isMovable(){
    return true;
}

int Merchant::dropGoldOnDeath(Cell* cell){
    if(cell){
        Treasure* gold = new MerchantTreasure(Player::getInstance());
        cell->setSymbol(SYM_GOLD);
        cell->setEntity(gold);
        gold->setX(cell->getRow());
        gold->setY(cell->getCol());
        gold->setSymbol(SYM_GOLD);
    }
    return 0;
}
