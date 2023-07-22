#ifndef ___ORC_H___
#define ___ORC_H___

#include "enemy.h"

class Halfling : public Enemy {
    private: 
        double chance;

    public:
        Halfling (int hp, int atk, int def, string race, char symbol, string name, double change);
        ~Halfling();
        int getChance();
        void setChance(double chance);
        bool chanceToMiss();
        int calculateDamageToPlayer() override;
};

#endif