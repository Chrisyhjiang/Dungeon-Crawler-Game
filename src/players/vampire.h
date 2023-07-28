#ifndef ___VAMPIRE_H___
#define ___VAMPIRE_H___

#include "player.h"
#include "../enemies/dwarf.h"
class Vampire : public Player {
    public:
        Vampire();
        //int calculateDmgToEnemy() override;
        void addReward(Enemy* enemy) override;
        void attackEnemy(Enemy* enemy) override;
        
};

#endif