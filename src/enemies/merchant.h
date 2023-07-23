#ifndef ___MERCHANT_H___
#define ___MERCHANT_H___

#include "enemy.h"

class Merchant : public Enemy {
    private: 
        bool hostile;

    public:
        Merchant(string race);
        Merchant(int hp, int atk, int def, string race, char symbol);
        ~Merchant();
        bool isHostile();
        void setHostile(bool hostile);
        int calculateDamageToPlayer() override;
        bool isMovable() override;

};


#endif