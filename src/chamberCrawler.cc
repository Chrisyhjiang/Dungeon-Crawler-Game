#include <sstream>
#include <iostream>
#include "chamberCrawler.h"

string ChamberCrawler::race = SHADE;


ChamberCrawler::ChamberCrawler(){}

ChamberCrawler::~ChamberCrawler(){
    //Todo:    
}

void ChamberCrawler::start(string floorFile, int level){

    floorLayoutFile =  (floorFile == "") ? EMPTY_FLOOR_FILE : floorFile;
    floorStream = new ifstream(floorLayoutFile);
    player = PlayerFactory::createPlayer(race);
    loadFloor(player, level);
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
            ChamberCrawler::race = SHADE;
            break;
        case 2 :
            ChamberCrawler::race = DROW;
            break;
        case 3 :
            ChamberCrawler::race = VAMPIRE;
            break;
        case 4 :
            ChamberCrawler::race = TROLL;
            break;
        case 5 :
            ChamberCrawler::race = GOBLIN;
            break;
        default:
            break;
    }

}

void ChamberCrawler::loadFloor(Player* player, int n){
    floor = new Floor(n);
    floor->loadFromFile(floorStream);
    floor->spawnPlayers(player);
    floor->spawnFloor(player);
    floor->displayFloor(player);
}

bool ChamberCrawler::play(){

   while(true){
        bool result = floor->movePlayer(player);
        if(result){
            if(player->getCellSymbol() == SYM_STAIRS){
                //setLevel(getLevel()+1);
                start("", floor->getLevel()+1);
            }else{
                floor->displayFloor(player);
            }
        }
        floor->moveEnemies();
        floor->displayFloor(player);
    }
}
 
string ChamberCrawler::getRace(){
    return race;
}


 