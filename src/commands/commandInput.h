#ifndef ___COMMANDINPUT_H___
#define ___COMMANDINPUT_H___

#include <string>

using namespace std;

class CommandInput {
    private:
        string action;
        string direction;
        bool valid;
    public:
        
        CommandInput(string action, string direction, bool valid);
        ~CommandInput();
        string getAction();
        void setAction(string action);
        string getDirection();
        void setDirection(string direction);
        bool getIsValid();
        void setIsValid(bool valid);
        
};

#endif