#ifndef TREASURE_H
#define TREASURE_H

#include "itemDecorator.h"


class Treasure : public ItemDecorator {
    private:
        int gold;

    public:
        Treasure(Player* player, string name, int gold);
        ~Treasure();
        int getGold();
        void setGold(int g);
};



#endif