#ifndef ___CHARACTER_H___
#define ___CHARACTER_H___

#include <string>

using namespace std;

using namespace std;
class Character{
    private:
        int hp, atk, def, x, y;
        string race;
    public:
        Character(int hp, int atk, int def, string race);
        virtual ~Character() = 0;
        int getHP ();
        void setHP(int hp);
        int getAtk();
        void setAtk(int atk);
        int getDef();
        void setDef(int def);
        virtual bool isDead() = 0;
        string getRace();
        int getX();
        void setX(int x);
        int getY();
        void setY();
};

#endif

