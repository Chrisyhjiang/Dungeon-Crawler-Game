#ifndef ___HUMAN_H___
#define ___HUMAN_H___

#include "enemy.h"

class Human: public Enemy{
    private:
        int goldToDrop;
    
    public:
        Human(int hp, int atk, int def, string race, char symbol, string name, int goldToDrop);
        ~Human();
        int getGoldToDrop();
        void setGoldToDrop(int gold);
        int calculateDamageToPlayer() override;

};

#endif