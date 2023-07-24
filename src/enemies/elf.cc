#include "elf.h"

Elf::Elf(string race) : Enemy(140, 30, 10, race, ENEMY_ELF), extraAtk(2) {}
Elf::Elf(int hp, int atk, int def, string race, char symbol, int extraAtk) : Enemy(hp, atk, def, race, symbol), extraAtk(extraAtk){}

int Elf::getExtraAtk(){
    return extraAtk;
}
void Elf::setExtraAtk(int extraAtk){
    this->extraAtk = extraAtk;
}

int Elf::calculateDamageToPlayer(){
    return this->getAtk();
}

bool Elf::isMovable(){
    return true;
}