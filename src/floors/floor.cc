#include "floor.h"
using namespace std;

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

Floor::Floor() {
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
            map[i][j] = new Cell::Cell(i, j, line[i]);
        }
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
