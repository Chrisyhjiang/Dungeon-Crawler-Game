#include <iostream>
#include "chamberCrawler.h"
using namespace std;



int main(int argc, char* argv[]) {
    ChamberCrawler::setGameRace();
    srand(static_cast<unsigned int>(time(0)));
    ChamberCrawler *game = new ChamberCrawler();
    // Todo: pass default file for now
    game->start("");


    
}
