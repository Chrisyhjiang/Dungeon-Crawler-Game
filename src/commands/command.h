#ifndef ___COMMAND_H___
#define ___COMMAND_H___

using namespace std;

class Command {
    public:
        virtual ~Command() {};
        virtual string execute() = 0;
};

#endif
