#ifndef MERCHANTTREASURE_H
#define MERCHANTTREASURE_H

#include "itemDecorator.h"

class MerchantTreasure : public ItemDecorator {
    public:
        MerchantTreasure();
        ~MerchantTreasure();
        void update();
};

#endif
