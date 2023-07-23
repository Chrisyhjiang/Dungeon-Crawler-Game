#include "floor.h"
#include <iostream>
#include "chamber.h"
using namespace std;

class Chamber;
class Cell;

Floor::Floor() {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            map[i][j] = nullptr;
        }
    }
    for (int i = 0; i < MAX_CHAMBERS; i++) {
        chambers[i] = nullptr;
    }
}

Floor::~Floor() {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            delete map[i][j];
        }
    }

    for (int i = 0; i < MAX_CHAMBERS; i++) {
        delete chambers[i];
    }
}

void Floor::loadFromFile(std::ifstream *floorStream) {
    string line;
    for (int i = 0; i < MAX_ROW; i++) {
        getline(*floorStream, line);
        for (int j = 0; j < MAX_COLUMN; j++) {
            Cell* c = new Cell(i, j, line[i]);
            if (c->getSymbol() == '.') {
                int chamberID = locateChamber(i, j);
                c->setChamberID(chamberID);
                chambers[chamberID]->addCell(c);
            } else {
                c->setChamberID(-1);
            }
        }
    }
}

int Floor::locateChamber(int i, int j) {
    if (3 <= i && i <= 6 && 3 <= j && j <=  29) {
        return 0;
    } else if (15 <= i && i <= 22 && 4 <= j && j <= 25) {
        return 1;
    } else if (10 <= i && i <= 12 && 38 <= j && j <= 50) {
        return 4;
    } else if ((16 <= i && i <= 18 && 65 <= j && j <= 75) 
            || (19 <= i && i <= 21 && 37 <= j && j <= 75 )) {
        return 3;
    } else {
        return 2;
    }
}

void Floor::displayFloor() {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            if (map[i][j]) {
                cout << map[i][j]->getSymbol();
            } else {
                cout <<  ' ';
            }
        }
        cout << endl;
    }
}

Chamber* Floor::getRandomChamber() {
    return chambers[rand() % MAX_CHAMBERS];
}

void Floor::spawnPotions() {
    for (int i = 0; i < NUM_POTION; i++) {
        Chamber* c = Floor::getRandomChamber();
        c->renderPotion();
    }
}

void Floor::spawnEnemies() {
    for (int i = 0; i < NUM_ENEMY; i++) {
        Chamber* c = Floor::getRandomChamber();
        c->renderEnemy();
    }
}

void Floor::spawnTreasures() {
    for (int i = 0; i < NUM_TREASURES; i++) {
        Chamber* c = Floor::getRandomChamber();
        c->renderTreasure();
    }
}

void Floor::spawnStairs() {
    Chamber* c = Floor::getRandomChamber();
    
}

Cell* Floor::getCell(int i, int j) {
    return map[i][j];
}

void Floor::spawnFloor() {
    spawnPlayers();
    spawnStairs();
    spawnPotions();
    spawnTreasures();
    spawnEnemies();
}