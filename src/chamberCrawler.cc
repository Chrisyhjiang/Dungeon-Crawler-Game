#include <sstream>
#include <iostream>
#include "chamberCrawler.h"

ChamberCrawler::ChamberCrawler(){

}

ChamberCrawler::~ChamberCrawler(){
    //Todo:    
}

void ChamberCrawler::start(string race, string floorFile){
    floorLayoutFile =  (floorFile == "") ? EMPTY_FLOOR_FILE : floorFile;
    floorStream = new ifstream(floorLayoutFile);
    player = PlayerFactory::createPlayer(race);
    loadFloor();
    // displayFloor;
    // start game loop

}

string  ChamberCrawler::chooseGameRace(){
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
    string result = "";
    switch (number){
        case 1 :
            result = SHADE;
            break;
        case 2 :
            result = DROW;
            break;
        case 3 :
            result = VAMPIRE;
            break;
        case 4 :
            result = TROLL;
            break;
        case 5 :
            result = GOBLIN;
            break;
        default:
            break;
    }
    return result;
}

void ChamberCrawler::loadFloor(){
    floor = new Floor();
    floor->loadFromFile(floorStream);
    //floor->spawnFloor();
    floor->displayFloor();
}

void displayFloor(){
    // display floor;
}