#ifndef ___ORC_H___
#define ___ORC_H___

#include "enemy.h"

class Orc : public Enemy {
    private: 
        int extraDamage;

    public:
        Orc(int hp, int atk, int def, string race, char symbol, string name, int extraDamage);
        ~Orc();
        int getExtraDamage();
        void setExtraDamage(int extraDamage);
        int calculateDamageToPlayer() override;

};

#endif