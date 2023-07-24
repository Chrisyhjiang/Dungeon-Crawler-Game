#include "drow.h"

//Player::Player(int hp, int atk, int def, string race, int maxHP, int gold)

Drow::Drow() : Player(150, 25, 15, DROW, 150, 0){}

int Drow::calculateDmgToEnemy(Enemy* en){
    return this->getAtk();
}

void Drow::addReward(Enemy* enemy){
    // no reward to add
}