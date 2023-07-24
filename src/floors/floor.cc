#include "floor.h"
#include <iostream>

using namespace std;

class Chamber;
class Cell;

Floor::Floor() {

    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            cells[i][j] = new Cell(i, j, ' ');
        }
    }

    for (int i = 0; i < MAX_CHAMBERS; i++) {
        chambers[i] = new Chamber(i);
    }
}

Floor::~Floor() {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            delete cells[i][j];
        }
    }

    for (int i = 0; i < MAX_CHAMBERS; i++) {
       delete chambers[i];
    }
}

void Floor::loadFromFile(ifstream *floorStream) {
    string line;
    for (int i = 0; i < MAX_ROW; i++) {
        getline(*floorStream, line);
        for (int j = 0; j < MAX_COLUMN; j++) {
            cells[i][j] = new Cell(i, j, line[j]);
            if ( cells[i][j]->getSymbol() == SYM_TILE) {
                int chamberID = locateChamber(i, j);
                cells[i][j]->setChamberID(chamberID);
                chambers[chamberID]->addCell(cells[i][j]);
            } else {
                 cells[i][j]->setChamberID(-1);
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
            if (cells[i][j]) {
                cout << cells[i][j]->getSymbol();
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

void Floor::spawnPotions(Player* player) {
    for (int i = 0; i < NUM_POTION; i++) {
        Chamber* cell = getRandomChamber();
        cell->renderPotion(player);
    }
}

void Floor::spawnEnemies() {
    for (int i = 0; i < NUM_ENEMY; i++) {
        Chamber* chamber = getRandomChamber();
        //cout <<  "chamber id: " << chamber->getChamberID() << endl;
        chamber->renderEnemy();
    }
}

void Floor::spawnTreasures(Player* player) {
    for (int i = 0; i < NUM_TREASURES; i++) {
        Chamber* c = Floor::getRandomChamber();
        c->renderTreasure(player);
    }
}

void Floor::spawnStairs() {
    Chamber* chamber = getRandomChamber();
    chamber->renderStairs();   
}

Cell* Floor::getCell(int i, int j) {
    return cells[i][j];
}

void Floor::spawnPlayers(Player* player){
    Chamber* chosenChamber = getRandomChamber();
    Cell * cell = chosenChamber->getRandomCell();
    player->setX(cell->getRow());
    player->setY(cell->getCol());
    cell->setSymbol(SYM_PLAYER);
    cell->setCharacter(player);
}

void Floor::spawnFloor(Player* player) {
    spawnStairs();
    spawnEnemies();
    spawnPotions(player);
    spawnTreasures(player);
}
