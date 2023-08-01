#include "troll.h"

Troll::Troll() : Player(120, 25, 15, TROLL, 120, 0) {}

bool Troll::attackEnemy(Enemy* en) {
    Player::attackEnemy(en);
    int hp = this->getHP() + 5;
    this->setHP(std::min(this->getMaxHp(), hp));  
    return true;
}

