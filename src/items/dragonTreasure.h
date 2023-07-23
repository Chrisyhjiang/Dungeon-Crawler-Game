#ifndef DRAGONTREASURE_H
#define DRAGONTREASURE_H

#include "itemDecorator.h"

class DragonTreasure : public ItemDecorator {
    public:
        DragonTreasure();
        ~DragonTreasure();
        void update();
};

#endif
