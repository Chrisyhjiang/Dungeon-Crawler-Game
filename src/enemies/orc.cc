#include "orc.h"

Orc::Orc(int hp, int atk, int def, string race, char symbol, string name, int extraDamage) : Enemy(hp, atk, def, race, symbol, name), extraDamage(extraDamage){}
Orc::~Orc(){
    //Todo:
}
int Orc::getExtraDamage(){
    return extraDamage;
}
void Orc::setExtraDamage(int extraDamage){
    this->extraDamage = extraDamage;
}

int calculateDamageToPlayer(){
    //Todo:
}