#ifndef ___ORC_H___
#define ___ORC_H___

#include "enemy.h"
#include "../constants.h"
#include "../players/player.h"

class Orc : public Enemy {
    private: 
        double extraDamage;

    public:
        Orc(string race);
        Orc(int hp, int atk, int def, string race, char symbol, double extraDamage);
        ~Orc();
        double getExtraDamage();
        void setExtraDamage(double extraDamage);
        int calculateDamageToPlayer() override;
        bool isMovable() override;

};

#endif