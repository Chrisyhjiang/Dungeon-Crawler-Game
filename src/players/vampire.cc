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
    Dwarf* d = dynamic_cast<Dwarf*>(en);
    if (d) {
        this->setHP(this->getHP() - 5);
    } else {
        this->setHP(this->getHP() + 5);
    }
    
}
