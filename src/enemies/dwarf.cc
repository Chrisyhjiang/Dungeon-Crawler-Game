#include "dwarf.h"

Dwarf::Dwarf(string race): Enemy(100, 20, 30, race, Enemy::ENEMY_DWARF){};
Dwarf::Dwarf(int hp, int atk, int def, string race, char symbol) : Enemy(hp, atk, def, race, symbol){}
Dwarf::~Dwarf(){
    //Todo:
}

int calculateDamageToPlayer(){
    //Todo:
}

bool isMovable(){
    return true;
}