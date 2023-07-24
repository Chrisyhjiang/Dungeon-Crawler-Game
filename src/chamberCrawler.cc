#include <sstream>
#include <iostream>
#include "chamberCrawler.h"

string ChamberCrawler::race = SHADE;

ChamberCrawler::ChamberCrawler(){

}

ChamberCrawler::~ChamberCrawler(){
    //Todo:    
}

void ChamberCrawler::start(string floorFile){

    floorLayoutFile =  (floorFile == "") ? EMPTY_FLOOR_FILE : floorFile;
    floorStream = new ifstream(floorLayoutFile);
    player = PlayerFactory::createPlayer(race);
    loadFloor(player);
    // displayFloor;
    // start game loop

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

void ChamberCrawler::loadFloor(Player* player){
    floor = new Floor();
    floor->loadFromFile(floorStream);
    floor->spawnPlayers(player);
    floor->spawnFloor();
    floor->displayFloor();
}

void displayFloor(){
    // display floor;
}