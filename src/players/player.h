#ifndef ___PLAYER_H___
#define ___PLAYER_H___

#include <string>
#include <iostream>
#include "../constants.h"
#include "../enemies/enemy.h"
#include "../character.h"
#include "../floors/cell.h"
#include "playerFactory.h"

using namespace std;

class Player : public Character{
    private:
        int gold;
        int maxHp;
        char cellSymbol;
        static Player *instance;
        static string race;
        
    public:
        Player(int hp, int atk, int def, string race, int maxHP, int gold);
        ~Player() override;
        void move(Cell* nextCell);
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
        //char getSymbol();
        char getCellSymbol();
        void setCellSymbol (char symbol);
        static void setRace(string race);
        static string getRace();
};
#endif
