#ifndef ___VAMPIRE_H___
#define ___VAMPIRE_H___

#include "player.h"
#include "../enemies/dwarf.h"

class Vampire : public Player {
    public:
        Vampire();
        bool attackEnemy(Enemy* enemy) override;
        
};

#endif
