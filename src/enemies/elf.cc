#include "elf.h"

Elf::Elf(int hp, int atk, int def, string race, char symbol int extraAtk) : Enemy(hp, atk, def, race, symbol), extraAtk(extraAtk){}

Elf::~Elf(){
    //Todo:
}
int Elf::getExtraAtk(){
    return extraAtk;
}
void Elf::setExtraAtk(int extraAtk){
    this->extraAtk = extraAtk;
}

int calculateDamageToPlayer(){
    //Todo:
}

bool isMovable(){
    return true;
}