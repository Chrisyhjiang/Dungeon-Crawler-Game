#include <sstream>
#include <iostream>
#include "chamberCrawler.h"



ChamberCrawler::ChamberCrawler(){}

ChamberCrawler::~ChamberCrawler(){
    //Todo:    
}

void ChamberCrawler::start(string floorFile, int level){

    floorLayoutFile =  (floorFile == "") ? EMPTY_FLOOR_FILE : floorFile;
    floorStream = new ifstream(floorLayoutFile);

        // player = PlayerFactory::createPlayer(race);
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
    floor->displayFloor();
}

bool ChamberCrawler::play(){

   while(true){
       // Player* player = Player::getInstance();
        bool result = floor->movePlayer();
        if(result){
            Player* player = Player::getInstance();
            if(player->getCellSymbol() == SYM_STAIRS){
                //setLevel(getLevel()+1);
                start("", floor->getLevel()+1);
            }else{
                floor->displayFloor();
            }
        }
        floor->moveEnemies();
        floor->displayFloor();
    }
}
 
// string ChamberCrawler::getRace(){
//     return race;
// }


 