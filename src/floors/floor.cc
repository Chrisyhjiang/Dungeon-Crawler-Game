#include "floor.h"

using namespace std;

class Chamber;
class Cell;

Floor::Floor(int level) : level(level) {

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

int Floor::getLevel(){
    return level;
}

void Floor::setLevel(int n){
    level = n;
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

void Floor::displayFloor(string actionMsg) {
    for (int i = 0; i < MAX_ROW; i++) {
        for (int j = 0; j < MAX_COLUMN; j++) {
            if (cells[i][j]) {
                char s = cells[i][j]->getSymbol();
                auto it = colorMap.find(s);
                if ( it != colorMap.end()){
                      cout << it->second << s << ANSI_RESET;
                } else {
                    cout << s; 
                }
            } else {
                cout <<  ' ';
            }
        }
        cout << endl;
    }
    Player* player = Player::getInstance();
    cout << "Race: " << Player::getRace() << " Gold: " << player->getGold() << "\t\t\t\t\t\t\tFloor " << getLevel() << endl; 
    cout << "HP: " << player->getHP() << endl;
    cout << "Atk: " << player->getAtk() << endl;
    cout << "Def: " << player->getDef() << endl;
    cout << "Action: " << actionMsg << endl;

}

Chamber* Floor::getRandomChamber() {
    return chambers[rand() % MAX_CHAMBERS];
}

void Floor::spawnPotions() {
    for (int i = 0; i < NUM_POTION; i++) {
        Chamber* cell = getRandomChamber();
        cell->renderPotion();
    }
}

void Floor::spawnEnemies() {
    for (int i = 0; i < NUM_ENEMY; i++) {
        Chamber* chamber = getRandomChamber();
        chamber->renderEnemy();
    }
}

 
void Floor::spawnTreasures() {
   
    for (int i = 0; i < NUM_TREASURES; i++) {
        Chamber* c = Floor::getRandomChamber();
        ItemDecorator* gold = c->renderTreasure();
        DragonTreasure* dt =  dynamic_cast<DragonTreasure*>(gold);
        if(dt){
            cout << "dragonTreasure spawned ..." << endl;
            // spawn a dragon
            bool found = false;
            while(!found){
                string dir = DIRECTIONS[std::rand() % 8];
                Cell* cell = getNeighbourCell(dir, dt);
                if(!cell->isOccupied()){
                    // spawn a dragon to guard the DragonTreasure
                    found = true;
                    Enemy* enemy = EnemyFactory::createEnemy(ENEMY_DRAGON, Player::getRace());
                    cell->setSymbol(ENEMY_DRAGON);
                    cell->setEntity(enemy);
                    enemy->setX(cell->getRow());
                    enemy->setY(cell->getCol());
                }
            }
        }
    }
}

void Floor::spawnStairs() {
    Chamber* chamber = getRandomChamber();
    chamber->renderStairs();   
}

Cell* Floor::getCell(int i, int j) {
    return cells[i][j];
}

void Floor::spawnPlayers(){
    Chamber* chosenChamber = getRandomChamber();
    Cell * cell = chosenChamber->getRandomCell();
    Player* player = Player::getInstance();
    player->setX(cell->getRow());
    player->setY(cell->getCol());
    cell->setSymbol(SYM_PLAYER);
    cell->setEntity(player);
}

void Floor::spawnFloor() {
    spawnTreasures();
    spawnStairs();
    spawnEnemies();
    spawnPotions();
    
}

bool Floor::canMovePlayer(Cell* cell){
    char symbol = cell->getSymbol();
    return (!cell->isOccupied()) || (symbol == SYM_DOORWAY) || (symbol == SYM_PASSAGE) || (symbol == SYM_STAIRS);
}

Enemy* Floor::canPlayerAttack(string direction){
    Cell* cell = getNeighbourCell(direction, Player::getInstance());
    Enemy* enemy = dynamic_cast<Enemy*>(cell->getEntity());
    return enemy;
}

ItemDecorator* Floor::canPlayerTakePotion(string direction){
    Cell* cell = getNeighbourCell(direction, Player::getInstance());
    ItemDecorator* potion = dynamic_cast<ItemDecorator*>(cell->getEntity());
    if (potion && potion->getSymbol() == SYM_POTION){
        cell->setSymbol(SYM_TILE);
        cell->setEntity(nullptr);
        return potion;
    }
    return nullptr;
}

void Floor::resetCurCell(Cell* cell, char symbol) {
    cell->setSymbol(symbol);
    cell->setEntity(nullptr);
}

string Floor::enemyTurn(){
    string msg = "";
    Player* p = Player::getInstance();
    for(int i = 0 ; i < MAX_ROW; i++){
        for(int j = 0; j < MAX_COLUMN; j++){
            Cell* current = cells[i][j];
             if(current->getChamberID() > -1){
                  Enemy* enemy = dynamic_cast<Enemy*>(current->getEntity());
                  if(enemy && !enemy->hasMoved()){
                    if (enemy->isDead()) {
                        msg += string(1, enemy->getSymbol()) + " was slain!\n";
                        current->setSymbol(SYM_TILE);
                        current->setEntity(nullptr);
                        continue;
                    }
                    if (enemy->isPlayerInRange(p->getX(), p->getY())) {
                        int x = enemy->attackPlayer(p->getRace(), p->getDef());
                        msg += string(1, enemy->getSymbol());
                        if (x > 0) {
                            p->takeDamage(x);
                            msg += " dealt " + std::to_string(enemy->calculateDamageToPlayer(p->getRace(), p->getDef())) 
                                                    + " damage to player\n";
                        } else {
                            msg += " missed\n";
                        }
                    } else {
                        Dragon* dragon = dynamic_cast<Dragon*>(enemy);
                        if(!dragon){
                            bool done = false;
                            while(!done){
                                int i = std::rand() % 8;
                                string dir = DIRECTIONS[i];
                                Cell* next = getNeighbourCell(dir, enemy);
                                if(!next->isOccupied() ){
                                    done = true;
                                    enemy->move(next);
                                    resetCurCell(current, SYM_TILE);
                                } 
                            }
                        }
                    }
                }
            }
        }
    }

    // reset back moved 
     for(int i = 0 ; i < MAX_ROW; i++){
        for(int j = 0; j < MAX_COLUMN; j++){
            Cell* current = cells[i][j];
            if(current->getChamberID() > -1){
                Enemy* enemy = dynamic_cast<Enemy*>(current->getEntity());
                if(enemy){
                    enemy->setMoved(false);
                }
            }
        }
     }
     return msg;      
}

bool Floor::movePlayer(string dir){
    bool done = false;
    Player* player = Player::getInstance();
    Cell* nextCell = getNeighbourCell(dir, player);
    if(canMovePlayer(nextCell)){
        resetCurCell(cells[player->getX()][player->getY()], player->getCellSymbol());
        player->move(nextCell);
        done = true;
    }
    return done;
}

Cell* Floor::getNeighbourCell(string dir, Entity* entity){
    int nextRow = entity->getX();
    int nextCol = entity->getY();
    if ( dir == NORTH){
        nextRow--;
    } else if ( dir == SOUTH){
        nextRow++;
    } else if ( dir == EAST) {
        nextCol++;
    } else if ( dir == WEST) {
        nextCol--;
    } else if ( dir == NORTH_EAST) {
        nextRow--;
        nextCol++;
    } else if ( dir == NORTH_WEST ) {
        nextRow--;
        nextCol--;
    } else if ( dir == SOUTH_EAST ) {
        nextRow++;
        nextCol++;
    } else if ( dir == SOUTH_WEST ) {
        nextRow++;
        nextCol--;
    }
    return cells[nextRow][nextCol];
}

