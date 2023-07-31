#include <iostream>
#include <filesystem>
#include "chamberCrawler.h"
using namespace std;



int main(int argc, char* argv[]) {
    srand(static_cast<unsigned int>(time(0)));
    ChamberCrawler *game = new ChamberCrawler();
    if(argc > 1){
        if (!std::filesystem::is_regular_file(argv[1])) {
            std::cout << "The provided argument is not a file.\n";
            return 1;
        }else {
             game->start(argv[1], true);
        }
       
    }else{
         game->start("", true);
    }
    delete game;
}
