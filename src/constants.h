#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using namespace std;

const int MAX_LEVEL = 5;
const int MAX_CHAMBERS = 5;
const int MAX_ROW = 25;
const int MAX_COLUMN = 79;
const int NUM_GOLD = 10;
const int NUM_POTION = 10;
const int NUM_ENEMY = 20;
const int NUM_TREASURES = 10;

// constants for players
const string SHADE = "Shade";
const string DROW = "Drow";
const string VAMPIRE = "Vampire";
const string TROLL = "Troll";
const string GOBLIN = "Goblin";
const char SYM_PLAYER = '@';

// constants for floor elements
char const SYM_WALL_VER = '|';
char const SYM_WALL_HOR = '-';
char const SYM_DOORWAY = '+';
char const SYM_PASSAGE = '#';
char const SYM_TILE = '.';
char const STAIRS = '\\';

// constants for potion and gold
char const GOLD = 'G';
char const POTION = 'P';

#endif