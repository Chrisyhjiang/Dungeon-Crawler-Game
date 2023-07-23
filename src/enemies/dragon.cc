#include "dragon.h"


Dragon::Dragon(string race) : Enemy(100, 20, 20, race, Enemy::ENEMY_DRAGON){};
Dragon::Dragon(int hp, int atk, int def, string race, char symbol): Enemy(hp, atk, def, race, symbol){};

Dragon::~Dragon(){

}

TreasureHoard* Dragon::getHoard(){
    return hoard;
}

void Dragon::setTreasureHoard(TreasureHoard* hoard){
    this->hoard = hoard;
}

int calculateDamageToPlayer(){
    //Todo: 
}

void guard(){
    
}

 bool isMovable(){
    return false;
 }