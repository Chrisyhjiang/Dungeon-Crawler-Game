#include "itemDecorator.h"


ItemDecorator::ItemDecorator(Player* p){
    target = p;
}

ItemDecorator::~ItemDecorator() {
    delete target;
}

void ItemDecorator::setTarget(Player* p) {
    target = p;
}

void ItemDecorator::update(){
    
}
