#ifndef BOOSTDEF_H
#define BOOSTDEF_H

#include "itemDecorator.h"

class BoostDefPotion : public ItemDecorator{
    public:
        BoostDefPotion();
        BoostDefPotion(Player* p);
        ~BoostDefPotion();
        void update();
};

#endif
