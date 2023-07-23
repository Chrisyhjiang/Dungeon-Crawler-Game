#ifndef ITEMDECORATOR_H
#define ITEMDECORATOR_H

#include "../players/player.h"

class ItemDecorator : public Player {
    protected:
        Player* target;
    public:
        ItemDecorator(Player* p);
        ItemDecorator();
        ~ItemDecorator();
        void setTarget(Player *p);
        virtual void update() = 0;
};



#endif