#include "player.h"
#include <algorithm>

using namespace std;

Player::Player(int hp, int atk, int def, string race, 
                int maxHP, int gold) : Character(hp, atk, def, race),
                maxHp(maxHp), gold(gold){}


Player::~Player() {

}

Player* Player::getInstance() {
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
    int diff = dmg - Character::getDef();
    if (diff > 0) {
        Character::setDef(0);
        Character::setHP(max(Character::getHP() - diff, 0));
    } else {
        Character::setDef(-1 * diff);
    }
}

int Player::calculateDmgToEnemy(Enemy* en) {
    return Character::getAtk();
}

bool Player::isDead() {
    return Character::getHP == 0;
}


