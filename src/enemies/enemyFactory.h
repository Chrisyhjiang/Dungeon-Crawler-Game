#ifndef ___ENEMYFACTORY_H___
#define ___ENEMYFACTORY_H___

#include <string>

using namespace std;

class Enemy;

class EnemyFactory{

    public:
        static Enemy* createEnemy(char en);

};

#endif;
