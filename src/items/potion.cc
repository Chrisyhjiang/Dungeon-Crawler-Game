#include "potion.h"

Potion::Potion(Player* player, string name, double magnify) : ItemDecorator(player, name), magnify(magnify){}

Potion::~Potion(){}

double Potion::getMagnify(){
    return magnify;
}

void Potion::setMaginify(double m){
    magnify = m;
}