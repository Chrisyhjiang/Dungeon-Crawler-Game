#ifndef ___ENEMY_H___
#define ___ENEMY_H___

#include <string>
#include "../character.h"

class Enemy : public Character{
    private:
        char symbol;
        string name;
        bool movable;
    
    public:
        static char const ENEMY_HUMAN = 'H';
		static char const ENEMY_DWARF = 'W';
		static char const ENEMY_ELF = 'E';
		static char const ENEMY_ORC = 'O';
		static char const ENEMY_MERCHANT = 'M';
		static char const ENEMY_DRAGON = 'D';
		static char const ENEMY_HALFING = 'L';

        Enemy(int hp, int atk, int def, string race, char symbol, string name);
        ~Enemy();
        char getSymbol();
        void setSymbol(char symbol);
        string getName();
        void setName(string name);
        void attachPlayer();
        bool isPlayerInRange();
        void takeDamage(int damage);
        virtual int calculateDamageToPlayer() = 0;
        bool isDead() override;
        int giveRewardToPlayer();
        virtual bool isMovable() = 0;
};

#endif