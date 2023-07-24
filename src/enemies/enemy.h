#ifndef ___ENEMY_H___
#define ___ENEMY_H___

#include <string>
#include "../character.h"


class Enemy : public Character{
    private:
        char symbol;
        bool movable;
    public:
    
        Enemy(int hp, int atk, int def, string race, char symbol);
        ~Enemy() override;
        char getSymbol();
        void setSymbol(char symbol);
        void attachPlayer();
        bool isPlayerInRange();
        void takeDamage(int damage);
        virtual int calculateDamageToPlayer() = 0;
        bool isDead() override;
        int giveRewardToPlayer();
        virtual bool isMovable() = 0;
};

#endif