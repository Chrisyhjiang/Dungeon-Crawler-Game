#include "player.h"
#include <algorithm>

using namespace std;

Player::Player(string race) {
    this->setRace(race);
}

Player::Player(int hp, int atk, int def, string race, int maxHP, int gold) : Character(hp, atk, def, race){
    this->setMaxHp(maxHp);
    this->setGold(gold);
}


Player::~Player() {
    // todo:
}

// Player* Player::getInstance() {
//     return instance;
// }

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

void Player::setRace(string race){
    this->setRace(race);
}


