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
   return true;
}

void Enemy::takeDamage(int damage){

}

int Enemy::calculateDamageToPlayer(){
    return this->getAtk();
}

bool Enemy::isDead(){
    return true;
}

int Enemy::giveRewardToPlayer(){
    return 0;
}

bool Enemy::hasMoved(){
    return isMoved;
}

void Enemy::setMoved(bool moved){
    isMoved = moved;
}

void Enemy::move(Cell* cell){
    this->setX(cell->getRow());
    this->setY(cell->getCol());
    cell->setSymbol(this->getSymbol());
    cell->setEntity(this);
    isMoved = true;
}



