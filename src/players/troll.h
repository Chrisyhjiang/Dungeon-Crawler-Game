#ifndef ___TROLL_H___
#define ___TROLL_H___

#include "player.h"
#include <algorithm>

class Troll : public Player {
    public:
        Troll();
        //int calculateDmgToEnemy() override;
        void addReward(Enemy* enemy) override;
        void attackEnemy(Enemy* en) override;
};

#endif
