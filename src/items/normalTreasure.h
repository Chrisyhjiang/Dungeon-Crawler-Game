#ifndef NORMALTREASURE_H
#define NORMALTREASURE_H

#include "itemDecorator.h"

class NormalTreasure : public ItemDecorator {
    public:
        NormalTreasure();
        ~NormalTreasure();
        void update();
};

#endif
