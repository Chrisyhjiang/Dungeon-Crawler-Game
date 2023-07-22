#include "dragon.h"

Dragon::Dragon(int hp, int atk, int def, string race, char symbol, string name): Enemy(hp, atk, def, race, symbol, name){}

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