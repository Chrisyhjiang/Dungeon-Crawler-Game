#include <iostream>
#include "chamberCrawler.h"
using namespace std;



int main(int argc, char* argv[]) {
    ChamberCrawler *game = new ChamberCrawler();
    string race = game->chooseGameRace();
    cout << "race: " << race << endl;
    game->start(race, "");


    
}
