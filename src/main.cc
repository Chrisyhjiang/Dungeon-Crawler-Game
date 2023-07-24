#include <iostream>
#include "chamberCrawler.h"
using namespace std;



int main(int argc, char* argv[]) {
    ChamberCrawler::setGameRace();
    ChamberCrawler *game = new ChamberCrawler();
    // Todo: pass default file for now
    game->start("");


    
}
