#ifndef ___DRAGON_H___
#define ___DRAGON_H___

#include "enemy.h"
#include "treasureHoard.h"

class Dragon : public Enemy {
    private: 
        TreasureHoard * hoard;

    public:
        Dragon(string race);
        Dragon(int hp, int atk, int def, string race, char symbol);
        ~Dragon();
        TreasureHoard* getHoard();
        void setTreasureHoard(TreasureHoard* hoard);
        int calculateDamageToPlayer() override;
        void guard();
         bool isMovable() override;
};

#endif