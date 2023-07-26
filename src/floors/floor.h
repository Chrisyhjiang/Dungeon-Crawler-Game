#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include <iostream>
#include <map>
#include "cell.h"
#include "chamber.h"
#include "../constants.h"
#include "../players/player.h"

class Chamber;

class Floor {

	public:
		Floor(int level);
		~Floor();
		void loadFromFile(std::ifstream *floorStream);
		void displayFloor(string actionMsg);
        Cell *getCell(int i, int j);
		void spawnFloor();
		void spawnPlayers();
		bool movePlayer();
		string enemyTurn();
		int getLevel();
		void setLevel(int n);
		Enemy* canPlayerAttack(string direction);
		

	private:
		int locateChamber(int i, int j);
		Cell* cells[MAX_ROW][MAX_COLUMN];
		Chamber* chambers[MAX_CHAMBERS];
		map<char, string> colorMap = {	{SYM_PLAYER, ANSI_BLUE}, {SYM_STAIRS, ANSI_BLUE}, {GOLD, ANSI_YELLOW},
										{POTION, ANSI_GREEN},  {ENEMY_MERCHANT, ANSI_RED}, {ENEMY_DRAGON, ANSI_RED},
										{ENEMY_DWARF, ANSI_RED}, {ENEMY_ELF, ANSI_RED}, {ENEMY_HUMAN, ANSI_RED}, 
										{ENEMY_ORC, ANSI_RED}, {ENEMY_HALFING, ANSI_RED}};

		int level;
		void spawnEnemies();
		void spawnPotions();
		void spawnTreasures();
		void spawnStairs();
		bool canMovePlayer(Cell* cell);
		void resetCurCell(Cell* cell, char symbol);
		// void floodChamber(int i, int j, std::string (*rows)[MAX_ROW], std::vector<Tile *> *tiles);
		Chamber *getRandomChamber();
		string getColorCode(char c);
		 
		// Tile *getRandomTile();
};
#endif
