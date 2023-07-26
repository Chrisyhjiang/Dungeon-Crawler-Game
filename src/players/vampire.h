#ifndef ___VAMPIRE_H___
#define ___VAMPIRE_H___

#include "player.h"

class Vampire : public Player {
    public:
        Vampire();
        int calculateDmgToEnemy() override;
        void addReward(Enemy* enemy) override;
        
};

#endif