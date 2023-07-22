#ifndef ___MERCHANT_H___
#define ___MERCHANT_H___

#include "enemy.h"

class Merchant : public Enemy {
    private: 
        bool hostile;

    public:
        Merchant(int hp, int atk, int def, string race, char symbol, string name);
        ~Merchant();
        bool isHostile();
        void setHostile(bool hostile);
        int calculateDamageToPlayer() override;

};

#endif