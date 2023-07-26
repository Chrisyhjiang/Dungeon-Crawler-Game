#ifndef ITEMDECORATOR_H
#define ITEMDECORATOR_H

#include "../players/player.h"

class ItemDecorator {
    
    public:
        Player* target;
        ItemDecorator(Player* p);
        ~ItemDecorator();
        void setTarget(Player *p);
        virtual void update();
};



#endif