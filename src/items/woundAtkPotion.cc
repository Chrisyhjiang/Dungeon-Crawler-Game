#include "woundAtkPotion.h"


WoundAtkPotion::WoundAtkPotion(Player* p) : ItemDecorator(p) {

}

WoundAtkPotion::~WoundAtkPotion(){

}

void WoundAtkPotion::update() {
    target->setAtk(target->getAtk() - 5);
}

