#include <limits.h>
#include "vampire.h"


Vampire::Vampire() : Player(50, 25, 25, VAMPIRE, INT_MAX, 0) {}

// int Vampire::calculateDmgToEnemy(){
//     return this->getAtk();
// }

void Vampire::addReward(Enemy* enemy){
    // no reward to add
}

void Vampire::attackEnemy(Enemy* en) {
    Player::attackEnemy(en);
    this->setHP(this->getHP() + 5);
}
