#ifndef ___DROW_H___
#define ___DROW_H___

#include "player.h"

class Drow : public Player {
    public:
        Drow();
        int calculateDmgToEnemy() override;
        void addReward(Enemy* enemy) override;
        
};

#endif