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


const char SYM_GOLD = 'G';
const char SYM_POTION = 'P';

// constants for potion and gold
const string POTION_RH = "RH";
const string POTION_BA = "BA";
const string POTION_BD = "BD";
const string POTION_PH = "PH";
const string POTION_WA = "WA";
const string POTION_WD = "WD";
const string GOLD_SMALL = "GS";
const string GOLD_NORMAL = "GN";
const string GOLD_MERCHANT = "GM";
const string GOLD_DRAGON = "GD";

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
const string NORTH = "no";
const string SOUTH = "so";
const string EAST = "ea";
const string WEST = "we";
const string NORTH_EAST = "ne";
const string NORTH_WEST = "nw";
const string SOUTH_EAST = "se";
const string SOUTH_WEST = "sw";
const string CMD_ATTACK = "a";
const string CMD_POTION = "u";
const string CMD_GOLD = "f";
const string CMD_EXIT = "q";


const string DIRECTIONS[] = { NORTH, SOUTH, EAST, WEST, NORTH_EAST, NORTH_WEST, SOUTH_EAST, SOUTH_WEST};

// ANSI escape codes for text colors
const string ANSI_RESET = "\033[0m";
const string ANSI_RED = "\033[31m";
const string ANSI_GREEN = "\033[32m";
const string ANSI_YELLOW = "\033[33m";
const string ANSI_BLUE = "\033[34m";

// action 
const string ACTION_MSG_PLAYER_SPAWNED = "Player character has spawned";


#endif