#include <vector>
#include "commandInterpreter.h"
#include "playerMoveCommand.h"
#include "playerAttackCommand.h"
#include "playerUsePotionCommand.h"
#include "restartCommand.h"
#include "exitCommand.h"
#include "freezeCommand.h"

CommandInterpreter::CommandInterpreter(ChamberCrawler* game) : game(game) {};

CommandInput* CommandInterpreter::parseCommand(string line){
    vector<string> tokens;
    istringstream iss(line);
    string token;
    while (iss >> token) {
        tokens.push_back(token);
    }

    CommandInput* cmd = new  CommandInput("", "", false); 
    if(tokens.size() == 1){
        string first = tokens.at(0);
        if(isValidCmd(first)){
            cmd->setAction(first);
            cmd->setIsValid(true);
        }else if (isValidDirection(first)){
            cmd->setDirection(first);
            cmd->setIsValid(true);
        }
    }else if (tokens.size() == 2){
        string first = tokens.at(0);
        if(isValidCmd(first)){
            cmd->setAction(first);
            string second = tokens.at(1);
            if(isValidDirection(second)){
                cmd->setDirection(second);
                cmd->setIsValid(true);
            }
        }
    }
    return cmd;
}

string CommandInterpreter::executeCommand(string line){
    CommandInput* cmdInput = parseCommand(line);
    string result = "";
    if(cmdInput->getIsValid()){
        Command* cmd = nullptr;
        string action = cmdInput->getAction();
        string direction = cmdInput->getDirection();
        if(action == ""){
            // move command has no action only direction
            cmd = new PlayerMoveCommand(game, direction);
        }else if (action == CMD_ATTACK){
            cmd = new PlayerATKCommand(game, direction);
        } else if (action == CMD_POTION){
            cmd = new PlayerUsePotionCommand(game, direction);
        } else if (action == CMD_RESTART) {
            cmd = new RestartCommand(game);
        } else if (action == CMD_EXIT){
            cmd = new ExitCommand();
        } else if (action == CMD_FREEZE) {
            cmd = new FreezeCommand(game);
        }

        if(cmd){
            result = cmd->execute();
            delete cmd;
            
        }
    }
    delete cmdInput;
    return result;
    
}

bool CommandInterpreter::isValidCmd(string cmd){
    auto itr = find(std::begin(COMMANDS), end(COMMANDS), cmd);
    return itr != end(COMMANDS);
}

bool CommandInterpreter::isValidDirection(string direction){
    auto itr = find(std::begin(DIRECTIONS), end(DIRECTIONS), direction);
    return itr != end(DIRECTIONS);
}

