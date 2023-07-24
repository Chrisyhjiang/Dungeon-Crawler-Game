#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___

#include <string>
#include "constants.h"

using namespace std;
class Character{
    private:
        int hp, atk, def, x, y;
        static string race;
    public:
        Character();
        Character(int hp, int atk, int def, string race);
        virtual ~Character();
        int getHP ();
        void setHP(int hp);
        int getAtk();
        void setAtk(int atk);
        int getDef();
        void setDef(int def);
        virtual bool isDead() = 0;
        virtual string getRace();
        virtual void setRace(string r);
        int getX();
        void setX(int x);
        int getY();
        void setY(int y);
};

#endif

