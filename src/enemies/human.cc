#include "human.h"

Human::Human(int hp, int atk, int def, string race, char symbol, string name, int goldToDrop) : Enemy(hp, atk, def, race, symbol, name), goldToDrop(goldToDrop){}

Human::~Human(){
    //Todo:
}


int Human::getGoldToDrop(){
    return goldToDrop;
}

void Human::setGoldToDrop(int gold){
    this->goldToDrop = gold;
}


 int calculateDamageToPlayer(){
    //Todo:
 }