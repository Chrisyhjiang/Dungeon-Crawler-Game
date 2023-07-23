#include "chamber.h"

Chamber::Chamber(int id) : id{id}{}

Chamber::~Chamber() {
    while (!cells.empty()) {
        Cell *c = cells.back();
        delete c;
        cells.pop_back();
    }
}

void Chamber::renderEnemy() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }
}

void Chamber::renderTreasure() {

}

void Chamber::addCell(Cell* c) {
    cells.push_back(c);
}

void Chamber::renderPotion() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }
    // TODO GENERATE POTIONS IN THE CELLS
}

void Chamber::renderTreasure() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }

    // TODO GENERATE TREASURE IN THE CELLS
}

void Chamber::renderEnemy() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }
    // TODO GENERATE Enemy IN THE CELLS
}

void Chamber::renderStairs() {
    Cell *c = cells.at(rand() % cells.size());
    while (c->isOccupied()) {
        Cell *c = cells.at(rand() % cells.size());
    }
}


