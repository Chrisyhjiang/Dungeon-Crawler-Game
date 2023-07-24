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
        chambers[i] = new Chamber(-1);
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
    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(std::time(0)));
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
    Chamber* chamber = getRandomChamber();
    chamber->renderStairs();
    // Cell * cell = chamber->getRandomCell();
    // cell->setSymbol(SYM_STAIRS);   
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

void Floor::spawnFloor() {
    spawnStairs();
    // spawnPotions();
    // spawnTreasures();
    // spawnEnemies();
}

 

// Function to spawn the player in a chamber
// void spawnPlayerInChamber(Chamber* chambers[], int numChambers) {
//     // Seed the random number generator (called once at the start of the program)
//     std::srand(std::time(nullptr));

//     // Step 1: Randomly select a chamber
//     int chosenChamberIndex = std::rand() % numChambers;
//     Chamber* chosenChamber = chambers[chosenChamberIndex];

//     // Step 2: Randomly select a floor tile within the chosen chamber
//     int numRows = chosenChamber->getNumRows();
//     int numCols = chosenChamber->getNumCols();
//     int playerRow, playerCol;

//     do {
//         playerRow = std::rand() % numRows;
//         playerCol = std::rand() % numCols;
//     } while (!chosenChamber->isFloorTile(playerRow, playerCol) || chosenChamber->isOccupied(playerRow, playerCol));

//     // Step 3: Create the player instance and set its position in the chosen chamber
//     Player* player = new Player(/* Optional parameters for player initialization */);
//     chosenChamber->setEntity(player, playerRow, playerCol);
// }
