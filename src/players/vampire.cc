#include <limits.h>
#include "vampire.h"


Vampire::Vampire() : Player(50, 25, 25, VAMPIRE, INT_MAX, 0) {}

bool Vampire::attackEnemy(Enemy* en) {
    
    bool b = Player::attackEnemy(en);
    Dwarf* d = dynamic_cast<Dwarf*>(en);
    if (d) {
        this->setHP(this->getHP() - 5);
    } else {
        if (b) {
            this->setHP(this->getHP() + 5);
        }
    }
    return b;
}
