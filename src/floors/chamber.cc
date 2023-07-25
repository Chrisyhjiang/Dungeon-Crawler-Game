#include "chamber.h"
// #include "../items/normalTreasure.h"
// #include "../items/smallTreasure.h"
// #include "../items/dragonTreasure.h"
// #include "../items/boostAtk.h"
// #include "../items/boostDef.h"

Chamber::Chamber(int id) : id{id}{}

Chamber::~Chamber() {
    while (!chamberCells.empty()) {
        Cell *c = chamberCells.back();
        delete c;
        chamberCells.pop_back();
    }
}

vector<Cell*> Chamber::getCells(){
    return chamberCells;
}

void Chamber::renderEnemy() {
    int m = rand() % TOTAL_PROBABILITY_DISTRIBUTION;
    char enemyType;
    if (0 <= m && m < 4) {
        enemyType = ENEMY_HUMAN;
    } else if (4 <= m && m < 7) {
        enemyType = ENEMY_DWARF;
    } else if (7 <= m && m < 12) {
        enemyType= ENEMY_HALFING; 
    } else if (12 <= m && m < 14) {
        enemyType = ENEMY_ELF;
    } else if (14 <= m && m < 16) {
        enemyType = ENEMY_ORC;
    } else {
        enemyType = ENEMY_MERCHANT;
    }

    Enemy* enemy = EnemyFactory::createEnemy(enemyType, ChamberCrawler::getRace());
    Cell* cell = getRandomCell();
    cell->setSymbol(enemyType);
    cell->setCharacter(enemy);
    enemy->setX(cell->getRow());
    enemy->setY(cell->getCol());
}

void Chamber::renderTreasure(Player* player) {
    Cell* cell = getRandomCell();
    int m = rand() % 8;
    char e;
    ItemDecorator* gold;
    if (0 <= m && m < 5) {
        e = NORMAL_GOLD;
    } else if (5 <= m && m < 6) {
        e = DRAGON_GOLD;
    } else {
        e = SMALL_GOLD;
    }
    switch(e){
        case NORMAL_GOLD:
            gold = new NormalTreasure(player);
            break;
        case SMALL_GOLD:
            gold = new SmallTreasure(player);
            break;
        case DRAGON_GOLD:   
            gold = new DragonTreasure(player);
            break;
        default:
            gold = nullptr;
            break;
    }
    cell->setSymbol(GOLD);
    cell->setCharacter(gold);
    gold->setX(cell->getRow());
    gold->setY(cell->getCol());
}

void Chamber::addCell(Cell* c) {
    chamberCells.push_back(c);
}

void Chamber::renderPotion(Player* player) {
    Cell* cell = getRandomCell();
    int m = rand() % 6;
    ItemDecorator* potion;
    if (m == 0) {
        potion = new BoostAtkPotion(player);
    } else if (m == 1) {
        potion = new WoundAtkPotion(player);
    } else if (m == 2) {
        potion = new BoostDefPotion(player);
    } else if (m == 3) {
        potion = new WoundDefPotion(player);
    } else if (m == 4) {
        potion = new RestoreHealthPotion(player);
    } else {
        potion = new PoisonHealthPotion(player);
    }
    cell->setSymbol(POTION);
    cell->setCharacter(potion);
    potion->setX(cell->getRow());
    potion->setY(cell->getCol());
}

void Chamber::renderStairs() {
    Cell* cell = getRandomCell();

    cell->setSymbol(SYM_STAIRS);
}

Cell* Chamber::getRandomCell(){
    Cell* cell = nullptr;
    do{
        cell = chamberCells.at(rand() % chamberCells.size());
    }while(cell->isOccupied());
    return cell;
}


int Chamber::getChamberID(){
    return id;
}
