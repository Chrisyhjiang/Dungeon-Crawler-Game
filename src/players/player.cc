#include "player.h"
#include <algorithm>

using namespace std;

Player* Player::instance = nullptr;

string Player::race = SHADE;

// Player::Player(string race) {
//     this->setRace(race);
// }

Player::Player(int hp, int atk, int def, string race, int maxHP, int gold) : Character(hp, atk, def, race){
    this->setMaxHp(maxHp);
    this->setGold(gold);
    this->setSymbol(SYM_PLAYER);
    this->setCellSymbol(SYM_TILE);
}


Player::~Player() {
    // todo:
}

void Player::setRace(string s){
    race = s;
}

Player* Player::getInstance() {
    if(instance == nullptr){
        instance = PlayerFactory::createPlayer(race);
    }
    return instance;
}

int Player::getGold() {
    return gold;
}

void Player::setGold(int g) {
    gold = g;
}

int Player::getMaxHp() {
    return maxHp;
}

void Player::setMaxHp(int mh) {
    maxHp = mh;
}

void Player::takeDamage(int dmg) {
    int diff = dmg - this->getDef();
    if (diff > 0) {
        this->setDef(0);
        this->setHP(max(this->getHP() - diff, 0));
    } else {
        this->setDef(-1 * diff);
    }
}

bool Player::isDead() {
    return getHP() == 0;
}

void Player::attackEnemy(Enemy* enemy){
    int dmg = this->calculateDmgToEnemy(enemy);
    enemy->takeDamage(dmg);
    this->addReward(enemy);
}

int Player::calculateDmgToEnemy(Enemy *en){
    return this->getAtk();
}

string Player::getRace(){
    return race;
}


void Player::addReward(Enemy* en){
    
}

// char Player::getSymbol(){
//     return SYM_PLAYER;
// }

char Player::getCellSymbol(){
    return cellSymbol;
}

void Player::setCellSymbol(char symbol){
    cellSymbol = symbol;
}


void Player::move (Cell* nextCell) {
    this->setX(nextCell->getRow());
    this->setY(nextCell->getCol());
    cellSymbol = nextCell->getSymbol();
    nextCell->setSymbol(SYM_PLAYER);
    nextCell->setEntity(this);
}


