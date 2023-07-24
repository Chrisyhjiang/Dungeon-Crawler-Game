#include "dragon.h"


Dragon::Dragon(string race) : Enemy(100, 20, 20, race, ENEMY_DRAGON){};
Dragon::Dragon(int hp, int atk, int def, string race, char symbol): Enemy(hp, atk, def, race, symbol){};

Dragon::~Dragon(){

}

TreasureHoard* Dragon::getHoard(){
    return hoard;
}

void Dragon::setTreasureHoard(TreasureHoard* hoard){
    this->hoard = hoard;
}

int Dragon::calculateDamageToPlayer(){
    return this->getAtk();
}

void Dragon::guard(){
    
}

 bool Dragon::isMovable(){
    return false;
 }