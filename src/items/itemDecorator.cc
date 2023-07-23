#include "itemDecorator.h"
#include "../players/player.h"


ItemDecorator::ItemDecorator(Player* p) {
    target = p;
}

ItemDecorator::~ItemDecorator() {
    delete target;
}

void ItemDecorator::setTarget(Player* p) {
    target = p;
}

