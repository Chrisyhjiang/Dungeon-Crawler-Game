#ifndef ___GOBLIN_H___
#define ___GOBLIN_H___

#include "player.h"

class Goblin : public Player {
    public:
        Goblin();
        int calculateDmgToEnemy() override;
        void addReward(Enemy* enemy) override;
        
};

#endif