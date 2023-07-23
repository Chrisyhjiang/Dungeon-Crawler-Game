#include "enemy.h"


//Enemy::Enemy(int hp, int atk, int def, string race) : Character(hp, atk, def, race){};
Enemy::Enemy(int hp, int atk, int def, string race, char symbol) : Character(hp, atk, def, race), symbol(symbol){}

Enemy::~Enemy(){
    //Todo:
}

char Enemy::getSymbol(){
    return symbol;
}

void Enemy::setSymbol(char symbol){
    this->symbol = symbol;
}

void Enemy::attachPlayer(){

}

bool Enemy::isPlayerInRange(){

}

void takeDamage(int damage){

}

int calculateDamageToPlayer(){

}

bool isDead(){

}

int giveRewardToPlayer(){
    
}



