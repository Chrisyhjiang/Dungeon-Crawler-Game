#include "character.h"

Character::Character(int hp, int atk, int def, string race) : hp(hp), atk(atk), def(def) race(race){}

int Character::getHP(){
    return hp;
}

void Character::setHP(int hp){
    this->hp = hp;
}

int Character::getAtk(){
    return atk;
}

void Character::setAtk(int atk){
    this->atk = atk;
}

int Character::getDef(){
    return def;
}

void Character::setDef(int def){
    this->def = def;
}
 
string Character::getRace(){
    return race;
}

int Character::getX(){
    return x;
}

void Character::setX(int x){
    this->x = x;
}

int Character::getY(){
    return y;
}

void Character::setY(){
    this->y = y;
}
