#ifndef CHAMBER_H
#define CHAMBER_H
#include "cell.h"
#include "../constants.h"
#include "../enemies/enemy.h"
#include "../enemies/enemyFactory.h"
#include "../character.h"
#include "../items/itemDecorator.h"
#include "../items/smallTreasure.h"
#include "../items/normalTreasure.h"
#include "../items/dragonTreasure.h"
#include "../items/boostAtkPotion.h"
#include "../items/boostDefPotion.h"
#include "../items/woundAtkPotion.h"
#include "../items/woundDefPotion.h"
#include "../items/poisonHPPotion.h"
#include "../items/restoreHPPotion.h"
#include "stair.h"
#include <vector>
#include <cstdlib>
using namespace std;

class Potion;

class Chamber {
    private:
        // int size;
        int id;
        vector<Cell*> cells;
        Chamber(int id);
        ~Chamber();
    public:
        void renderPotion();
        void renderTreasure();
        void renderEnemy();
        void renderStairs();
        void addCell(Cell* c);
};

#endif
