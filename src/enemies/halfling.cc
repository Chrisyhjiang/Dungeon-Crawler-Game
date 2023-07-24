#include "halfling.h"
#include <cstdlib>
#include <ctime>


Halfling::Halfling(string race) : Enemy(100, 15, 20, race, ENEMY_HALFING), chance(0.5){};
Halfling::Halfling (int hp, int atk, int def, string race, char symbol, double chance) : Enemy(hp, atk, def, race, symbol), chance(chance){};
Halfling::~Halfling(){
    // todo
}

int Halfling::getChance(){
    return chance;
}

void Halfling::setChance(double chance){
    this->chance = chance;
}

bool Halfling::chanceToMiss(){

    std::srand(static_cast<unsigned>(std::time(0)));

    // Generate a random integer between 0 and RAND_MAX
    int r = std::rand();

    // Convert the integer to a double between 0 and 1
    double rv = static_cast<double>(r) / RAND_MAX;
    
    return (rv < chance);

}

int Halfling::calculateDamageToPlayer(){
    return this->getAtk();
}

bool Halfling::isMovable(){
    return true;
}