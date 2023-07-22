#include "merchant.h"

Merchant::Merchant(int hp, int atk, int def, string race, char symbol, string name) : Enemy(hp, atk, def, race, symbol, name){}

Merchant::~Merchant(){
    //Todo: 
}


 bool Merchant::isHostile(){
    return isHostile;
 }

void  Merchant::setHostile(bool hostile){
    this->hostile = hostile;
}

int calculateDamageToPlayer(){
    //Todo: 
}