#include "human.h"

Human::Human(string race) : Enemy(140, 20, 20, race, ENEMY_HUMAN), goldToDrop(2){}

Human::Human(int hp, int atk, int def, string race, char symbol, int goldToDrop) : Enemy(hp, atk, def, race, symbol), goldToDrop(goldToDrop){}

Human::~Human(){}

bool Human::isMovable(){
    return true;
}

int Human::dropGoldOnDeath(Cell* cell){
    if(cell){
        // actual it is 2 pile of normal treasure, but implement as a MerchantTreasure.
        Treasure* gold = new MerchantTreasure(Player::getInstance());
        cell->setSymbol(SYM_GOLD);
        cell->setEntity(gold);
        gold->setX(cell->getRow());
        gold->setY(cell->getCol());
        gold->setSymbol(SYM_GOLD);
    }
    return 0;
}

