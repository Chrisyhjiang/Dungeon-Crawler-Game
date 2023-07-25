#ifndef ___TREASUREHOARD_H___
#define ___TREASUREHOARD_H___

class TreasureHoard {
    private: 
        int gold;

    public:
        TreasureHoard(int gold);
        ~TreasureHoard();
        int getGoldAmount();
        void setGoldAmount(int gold);
};

#endif