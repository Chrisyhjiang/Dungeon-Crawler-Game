#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
using namespace std;

const int MAX_LEVEL = 5;
const string EMPTY_FLOOR_FILE = "emptySingleFloor.txt";
const int MAX_CHAMBERS = 5;
const int MAX_ROW = 25;
const int MAX_COLUMN = 79;
const int NUM_GOLD = 10;
const int NUM_POTION = 10;
const int NUM_ENEMY = 20;
const int NUM_TREASURES = 10;
const int TOTAL_PROBABILITY_DISTRIBUTION = 18;

// constants for players
const string SHADE = "Shade";
const string DROW = "Drow";
const string VAMPIRE = "Vampire";
const string TROLL = "Troll";
const string GOBLIN = "Goblin";
const string PLAYERS[] = {SHADE, DROW, VAMPIRE, TROLL, GOBLIN};
const char SYM_PLAYER = '@';

// constants for floor elements
const char SYM_WALL_VER = '|';
const char SYM_WALL_HOR = '-';
const char SYM_DOORWAY = '+';
const char SYM_PASSAGE = '#';
const char SYM_TILE = '.';
const char SYM_STAIRS = '\\';

// constants for potion and gold
const char GOLD = 'G';
const char POTION = 'P';

// constants for Enemy 
const char ENEMY_HUMAN = 'H';
const char ENEMY_DWARF = 'W';
const char ENEMY_ELF = 'E';
const char ENEMY_ORC = 'O';
const char ENEMY_MERCHANT = 'M';
const char ENEMY_DRAGON = 'D';
const char ENEMY_HALFING = 'L';

// constants for Gold
const char SMALL_GOLD = 'S';
const char NORMAL_GOLD = 'N';
const char MERCHANT_GOLD = 'M';
const char DRAGON_GOLD = 'D';

// command
//no,so,ea,we,ne,nw,se,sw
const string MOVE_NORTH = "no";
const string MOVE_SOUTH = "so";
const string MOVE_EAST = "ea";
const string MOVE_WEST = "we";
const string MOVE_NORTH_EAST = "ne";
const string MOVE_NORTH_WEST = "nw";
const string MOVE_SOUTH_EAST = "se";
const string MOVE_SOURTH_WEST = "sw";
const char USE_POTION = 'u';
const char EXIT = 'q';



#endif