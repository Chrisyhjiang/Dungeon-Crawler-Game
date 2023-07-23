#ifndef ___PLAYER_H___
#define ___PLAYER_H___

class Player {
        int gold, maxHP;
        static Player *player;

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
        int calculateDmgToEnemy(Enemy *en);
        bool isDead();
        int calculateReward(Enemy *en);
        static Player* getInstance();
        static void setRace(char race);
};
#endif
