#ifndef POTION_H
#define POTION_H

#include "itemDecorator.h"

class Potion : public ItemDecorator {
    private:
        double magnify;

    public:
        Potion(Player* player, string name, double magnify);
        ~Potion();
        double getMagnify();
        void setMaginify(double magnify);
};



#endif