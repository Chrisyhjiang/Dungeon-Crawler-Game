#include "woundAtkPotion.h"

WoundAtkPotion::WoundAtkPotion(Player* p, double magnify) : Potion (p, POTION_WA, magnify) {}

WoundAtkPotion::~WoundAtkPotion(){}

void WoundAtkPotion::update() {
    Player* target = this->getTarget();
    int atk = std::max(0, (int)(target->getAtk() - 5 * this->getMagnify()));
    target->setAtk(atk);
}

