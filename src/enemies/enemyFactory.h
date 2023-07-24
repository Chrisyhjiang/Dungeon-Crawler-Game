#ifndef ___ENEMYFACTORY_H___
#define ___ENEMYFACTORY_H___

#include <string>
#include "enemy.h"

using namespace std;

 

class EnemyFactory{
    public:
        static Enemy* createEnemy(char en, string race);
};

#endif
