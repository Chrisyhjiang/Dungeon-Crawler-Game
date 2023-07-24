#ifndef ITEMDECORATOR_H
#define ITEMDECORATOR_H

#include "../players/player.h"

class ItemDecorator : public Player {
    
    public:
        Player* target;
        ItemDecorator(Player* p);
        ItemDecorator();
        ~ItemDecorator();
        void setTarget(Player *p);
        virtual void update();
};



#endif