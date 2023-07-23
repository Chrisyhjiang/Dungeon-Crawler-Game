#ifndef POISONHP_H
#define POISONHP_H

#include "itemDecorator.h"

class PoisonHealthPotion : public ItemDecorator{
    public:
        PoisonHealthPotion();
        ~PoisonHealthPotion();
        void update();
};



#endif