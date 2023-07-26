#include "merchant.h"

Merchant::Merchant(string race) : Enemy(30, 70, 5, race, ENEMY_MERCHANT), hostile(false) {};
Merchant::Merchant(int hp, int atk, int def, string race, char symbol) : Enemy(hp, atk, def, race, symbol){}

Merchant::~Merchant(){
    //Todo: 
}


 bool Merchant::isHostile(){
    return hostile;
 }

void  Merchant::setHostile(bool hostile){
    this->hostile = hostile;
}


bool Merchant::isMovable(){
    return true;
}
