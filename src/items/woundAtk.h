#ifndef WOUNDATK_H
#define WOUNDATK_H

#include "itemDecorator.h"

class WoundAtkPotion : public ItemDecorator{
    public:
       WoundAtkPotion();
       ~WoundAtkPotion();
       void update(); 
};

#endif