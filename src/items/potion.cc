#include "potion.h"
#include "../items/itemDecorator.h"
#include "../items/boostAtkPotion.h"
#include "../items/boostDefPotion.h"
#include "../items/woundAtkPotion.h"
#include "../items/woundDefPotion.h"
#include "../items/poisonHPPotion.h"
#include "../items/restoreHPPotion.h"

Potion::Potion(Player* player, string name, double magnify) : ItemDecorator(player, name), magnify(magnify){}

Potion::~Potion(){}

double Potion::getMagnify(){
    return magnify;
}

void Potion::setMaginify(double m){
    magnify = m;
}

bool Potion::isPotion(char symbol){
    return (symbol >= '0') && (symbol <= '5');
}

Potion* Potion::createPotion(Player* player, char symbol, double magnify ){
    Potion* p;
    switch (symbol)
    {
    case '0':
        p = new RestoreHealthPotion(player, magnify);
        break;
    case '1':
        p = new BoostAtkPotion(player, magnify);  
        break;
    case '2':
        p = new BoostDefPotion(player, magnify);
        break;
    case '3':
        p = new PoisonHealthPotion(player, magnify);
        break;
    case '4':
        p = new WoundAtkPotion(player, magnify);
        break;
    case '5':
        p = new WoundDefPotion(player, magnify);
        break;
    default:
        break;
    }
    p->setSymbol(SYM_POTION);
    return p;
}

    // if (m == 0) {
    //    potion = new BoostAtkPotion(player, mag);  
    // } else if (m == 1) {
    //     potion = new WoundAtkPotion(player, mag);
    // } else if (m == 2) {
    //     potion = new BoostDefPotion(player, mag);
    // } else if (m == 3) {
    //     potion = new WoundDefPotion(player, mag);
    // } else if (m == 4) {
    //     potion = new RestoreHealthPotion(player, mag);
    // } else {
    //     potion = new PoisonHealthPotion(player, mag);
    // }
    // cell->setSymbol(SYM_POTION);
    // cell->setEntity(potion);
    // potion->setX(cell->getRow());
    // potion->setY(cell->getCol());
    // potion->setSymbol(SYM_POTION);