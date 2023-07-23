#ifndef CHAMBER_H
#define CHAMBER_H
#include "cell.h"
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
