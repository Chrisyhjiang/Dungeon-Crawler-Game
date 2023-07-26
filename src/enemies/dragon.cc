#include "dragon.h"


Dragon::Dragon(string race) : Enemy(100, 20, 20, race, ENEMY_DRAGON){};
Dragon::Dragon(int hp, int atk, int def, string race, char symbol): Enemy(hp, atk, def, race, symbol){};

Dragon::~Dragon(){

}

DragonTreasure* Dragon::getHoard(){
    return hoard;
}

void Dragon::setTreasureHoard(DragonTreasure* hoard){
    this->hoard = hoard;
}

void Dragon::guard(){
    
}

 bool Dragon::isMovable(){
    return false;
 }

bool Dragon::isPlayerInRange(int px, int py) {
    // TODO INCLUDE DRAGON HOARD ENTITY LOCATION. 
    return Enemy::isPlayerInRange(px, py);
}
