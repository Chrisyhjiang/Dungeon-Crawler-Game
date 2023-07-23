#ifndef RESTOREHP_H
#define RESTOREHP_H

#include "itemDecorator.h"

class RestoreHealthPotion : public ItemDecorator{
    public:
        RestoreHealthPotion();
        RestoreHealthPotion(Player* p);
        ~RestoreHealthPotion();
        void update();
};



#endif