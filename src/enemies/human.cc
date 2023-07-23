#include "human.h"
 //  Enemy(int hp, int atk, int def, string race, char symbol, string name);

Human::Human(string race) : Enemy(140, 20, 20, race, Enemy::ENEMY_HUMAN), goldToDrop(2){}

Human::Human(int hp, int atk, int def, string race, char symbol, int goldToDrop) : Enemy(hp, atk, def, race, symbol), goldToDrop(goldToDrop){}

Human::~Human(){
    //Todo:
}


int Human::getGoldToDrop(){
    return goldToDrop;
}

void Human::setGoldToDrop(int gold){
    this->goldToDrop = gold;
}

bool isMovable(){
    return true;
}

 int calculateDamageToPlayer(){
    //Todo:
 }