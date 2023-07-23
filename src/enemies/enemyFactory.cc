#include "enemy.h"
#include "enemyFactory.h"
#include "human.h"
#include "dwarf.h"
#include "elf.h"
#include "halfling.h"
#include "merchant.h"
#include "orc.h"
#include "dragon.h"

Enemy* EnemyFactory::createEnemy(char en, string race){
    Enemy* enemy;

    switch(en){
        case Enemy::ENEMY_HUMAN:
            enemy = new Human(race);
            break;
        case Enemy::ENEMY_DWARF:
            enemy = new Dwarf(race);
            break;
        case Enemy::ENEMY_ELF:
            enemy = new Elf(race);
            break;
        case Enemy::ENEMY_HALFING:
            enemy = new Halfling(race);
            break;
        case Enemy::ENEMY_MERCHANT:
            enemy = new Merchant(race);
            break;
        case Enemy::ENEMY_ORC:
            enemy = new Orc(race);
            break;
        case Enemy::ENEMY_DRAGON:
             enemy = new Dragon(race);
             break;
        default:
             enemy = nullptr;
    }

}