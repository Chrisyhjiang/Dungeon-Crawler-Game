#include <sstream>
#include <iostream>
#include <algorithm>
#include "chamberCrawler.h"




ChamberCrawler::ChamberCrawler(){}

ChamberCrawler::~ChamberCrawler(){
    //Todo:    
}

void ChamberCrawler::start(string floorFile, int level){
    floorLayoutFile =  (floorFile == "") ? EMPTY_FLOOR_FILE : floorFile;
    floorStream = new ifstream(floorLayoutFile);
    loadFloor(level);
    play();

}



void  ChamberCrawler::setGameRace(){
    cout << "please choose a game race from the following options: \n";
    for(int i = 0; i < 5; i++){
        cout << "enter " << i+1 << " for choosing " << PLAYERS[i] << endl;
    }
    std::cout << "Enter an integer between 1 and 5: ";
    int number;
    string input;
    while (getline(cin, input)) {
        stringstream ss(input);
        if (ss >> number) {
            if( number >= 1 && number <= 5) {
                break;
            }
        }  
        std::cout << "Invalid input. Please enter an integer between 1 and 5" << endl;
        
    }
    
    switch (number){
        case 1 :
            Player::setRace(SHADE);
            break;
        case 2 :
            Player::setRace(DROW);
            break;
        case 3 :
            Player::setRace(VAMPIRE);
            break;
        case 4 :
            Player::setRace(TROLL);
            break;
        case 5 :
            Player::setRace(GOBLIN);
            break;
        default:
            break;
    }

}

void ChamberCrawler::loadFloor(int n){
    floor = new Floor(n);
    floor->loadFromFile(floorStream);
    floor->spawnPlayers();
    floor->spawnFloor();
    floor->displayFloor("");
}

bool ChamberCrawler::play(){
   while(true){
        string actionMsg = "";
        actionMsg += playerTakeTurn();
        actionMsg += enemiesTakeTurn();
        // bool result = floor->movePlayer();
        // if(result){
        //     Player* player = Player::getInstance();
        //     if(player->getCellSymbol() == SYM_STAIRS){
        //         //setLevel(getLevel()+1);
        //         start("", floor->getLevel()+1);
        //     }else{
        //         floor->displayFloor();
        //     }
        // }
        // floor->moveEnemies();
        floor->displayFloor(actionMsg);
    }
}

string ChamberCrawler::playerTakeTurn(){
    string msg = "";
    while(true){
        cout << "enter a valid command: " ;
        string cmd;
        cin >> cmd;
        if(isValidCmd(cmd)){
            if (cmd == CMD_ATTACK){
                string dir;
                cin >> dir;
                if(isValidCmd(dir)){
                    msg = processPlayerAttackCmd(dir);
                    if(msg.size() > 0){
                        cout << msg;
                        break;
                    }else {
                         cout << "invalid command: no enemy to be attacked !!!" << endl; 
                    }
                }else{
                    cout << "invalid command: direction is invalid" << endl;
                } 
               
            } else if ( cmd == CMD_POTION){
                processPlayerUsePotionCmd();
                break;
            } else if ( cmd == CMD_EXIT){
                break;

            } else {
                processPlayerMoveCmd(cmd);
                break;
            }
        }else {
            cout << "command:" << cmd << " is invalid " << endl;
        }
    }
    return msg;
}

string ChamberCrawler::processPlayerAttackCmd(string direction){
    string actionMsg = "";
    Enemy* enemy = floor->canPlayerAttack(direction);
    if(enemy){
        Player* player = Player::getInstance();
        int damage = player->calculateDmgToEnemy();
        enemy->takeDamage(damage);
        actionMsg = "Enemy " + to_string(enemy->getSymbol()) + " (HP) " + to_string(enemy->getHP()) + " | take damage: " + to_string(damage);

    }
    return actionMsg;
}

void ChamberCrawler::processPlayerMoveCmd(string direction){

}

void ChamberCrawler::processPlayerUsePotionCmd(){

}

bool ChamberCrawler::isValidCmd(string cmd){
    if ( cmd == CMD_ATTACK || cmd == CMD_POTION || cmd == CMD_EXIT){
        return true;
    }
    auto it = find(std::begin(DIRECTIONS), end(DIRECTIONS), cmd);
    return it != end(DIRECTIONS);
}

string ChamberCrawler::enemiesTakeTurn(){
    return "";
}






 