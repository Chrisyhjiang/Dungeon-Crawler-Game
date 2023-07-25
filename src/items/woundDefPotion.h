#ifndef WOUNDDEF_H
#define WOUNDDEF_H

#include "itemDecorator.h"

class WoundDefPotion : public ItemDecorator{
    public:
       WoundDefPotion(Player* p);
       ~WoundDefPotion();
       void update(); 
};

#endif