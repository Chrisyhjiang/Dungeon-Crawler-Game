#ifndef ___COMMANDINTERPRETER_H___
#define ___COMMANDINTERPRETER_H___

#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include "command.h"
#include "commandInput.h"
#include "../constants.h"
#include "../chamberCrawler.h"


using namespace std;

class CommandInterpreter {
    private:
        ChamberCrawler* game;
        CommandInput* parseCommand(string line);
    public:
        CommandInterpreter(ChamberCrawler* game);
        string executeCommand(string s);
        bool isValidCmd(string cmd);
        bool isValidDirection(string direction);
        bool isValidRaceCmd(string cmd);
};

#endif
