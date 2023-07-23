#ifndef ___PLAYER_H___
#define ___PLAYER_H___

#include <string>
#include "enemy.h"
#include "../character.h"

using namespace std;

class Player : public Character{
        int gold, maxHp;
        string name;
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
        virtual int calculateReward(Enemy *en) = 0;
        static Player* getInstance();
        static void setRace(char race);
        string getName();
        void setName(string n);
    private:
        Player(int hp, int atk, int def, string race, int maxHP, int gold);
        ~Player();
};
#endif
