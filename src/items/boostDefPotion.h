#ifndef BOOSTDEFPOTION_H
#define BOOSTDEFPOTION_H

#include "itemDecorator.h"

class BoostDefPotion : public ItemDecorator{
    public:
        BoostDefPotion(Player* p);
        ~BoostDefPotion();
        void update();
};

#endif
