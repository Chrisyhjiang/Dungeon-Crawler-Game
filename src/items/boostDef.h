#ifndef BOOSTDEF_H
#define BOOSTDEF_H

#include "itemDecorator.h"

class BoostDefPotion : public ItemDecorator{
    public:
        BoostDefPotion();
        ~BoostDefPotion();
        void update();
};

#endif
