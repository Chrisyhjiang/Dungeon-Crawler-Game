#include "merchant.h"

Merchant::Merchant(string race) : Enemy(30, 70, 5, race, Enemy::ENEMY_MERCHANT), hostile(false) {};
Merchant::Merchant(int hp, int atk, int def, string race, char symbol) : Enemy(hp, atk, def, race, symbol){}

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

bool isMovable(){
    return true;
}
