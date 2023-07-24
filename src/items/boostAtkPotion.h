#ifndef BOOSTATTACK_H
#define BOOSTATTACK_H

#include "itemDecorator.h"

class BoostAtkPotion : public ItemDecorator{
    public:
        BoostAtkPotion(Player* p);
        ~BoostAtkPotion();
        void update();
};



#endif
