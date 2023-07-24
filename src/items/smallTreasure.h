#ifndef SMALLTREASURE_H
#define SMALLTREASURE_H

#include "itemDecorator.h"

class SmallTreasure : public ItemDecorator {
    public:
        SmallTreasure(Player* p);
        ~SmallTreasure();
        void update();
};

#endif
