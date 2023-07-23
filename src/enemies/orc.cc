#include "orc.h"

Orc::Orc(string race) : Enemy(180, 30, 25, race, Enemy::ENEMY_ORC), extraDamage(0.5) {};

Orc::Orc(int hp, int atk, int def, string race, char symbol, double extraDamage) : Enemy(hp, atk, def, race, symbol), extraDamage(extraDamage){};

Orc::~Orc(){
    //Todo:
}

double Orc::getExtraDamage(){
    return extraDamage;
}

void Orc::setExtraDamage(double extraDamage){
    this->extraDamage = extraDamage;
}

int calculateDamageToPlayer(){
    //Todo:
}

bool isMovable(){
    return true;
}