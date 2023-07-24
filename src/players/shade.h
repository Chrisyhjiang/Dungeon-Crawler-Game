#ifndef ___SHADE_H___
#define ___SHADE_H___

#include "player.h"

class Shade : public Player {
    public:
        Shade();
        int calculateDmgToEnemy(Enemy* enemy) override;
        void addReward(Enemy* enemy) override;
        
};

#endif