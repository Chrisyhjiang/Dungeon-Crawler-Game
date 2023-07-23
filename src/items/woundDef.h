#ifndef WOUNDDEF_H
#define WOUNDDEF_H

#include "itemDecorator.h"

class WoundDefPotion : public ItemDecorator{
    public:
       WoundDefPotion();
       ~WoundDefPotion();
       void update(); 
};

#endif