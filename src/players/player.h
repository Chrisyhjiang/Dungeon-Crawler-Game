#ifndef ___PLAYER_H___
#define ___PLAYER_H___

#include <string>
#include "constants.h"
#include "enemy.h"
#include "../character.h"

using namespace std;

class Player : public Character{
    private:
        int gold, maxHp;
        static Player *instance;

    public:

        bool move(string dir);
        void useItem(string dir);
        int getGold();
        void setGold(int g);
        void attackEnemy(Enemy *en);
        bool isEnemyInRange();
        void magnifyPotion(double m);
        int getMaxHp();
        void setMaxHp(int maxHp);
        void takeDamage(int dmg);
        virtual int calculateDmgToEnemy(Enemy *en);
        bool isDead();
        virtual void addReward(Enemy *en);
        static Player* getInstance();
        static void setRace(string race);
        Player();
        Player(int hp, int atk, int def, string race, int maxHP, int gold);
        ~Player();
};
#endif
