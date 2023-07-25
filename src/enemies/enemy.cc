#include "enemy.h"

Enemy::Enemy(int hp, int atk, int def, string race, char symbol, string name) : Character(hp, atk, def, race), symbol(symbol), name(name){}

Enemy::~Enemy(){
    //Todo:
}

char Enemy::getSymbol(){
    return symbol;
}


void Enemy::setSymbol(char symbol){
    this->symbol = symbol;
}

string Enemy::getName(){
    return name;
}

void Enemy::setName(string name){
    this->name = name;
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



