#include "troll.h"

Troll::Troll() : Player(120, 25, 15, TROLL, 120, 0) {
   // this->setCellSymbol(SYM_TILE);
}

// int Troll::calculateDmgToEnemy(){
//     return this->getAtk();
// }

void Troll::addReward(Enemy* enemy){
    // no reward to add
}


void Troll::attackEnemy(Enemy* en) {
    Player::attackEnemy(en);
    this->setHP(std::min(this->getHP() + 5, this->getMaxHp()));
}
