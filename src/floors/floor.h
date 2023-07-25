#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <ctime>
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
		void displayFloor(Player* player);
        Cell *getCell(int i, int j);
		void spawnFloor(Player* player);
		void spawnPlayers(Player* player);
		bool movePlayer(Player* player);
		int getLevel();
		void setLevel(int n);

	private:
		int locateChamber(int i, int j);
		Cell* cells[MAX_ROW][MAX_COLUMN];
		Chamber* chambers[MAX_CHAMBERS];
		int level;
	
		void spawnEnemies();
		void spawnPotions(Player* player);
		void spawnTreasures(Player* player);
		void spawnStairs();
		bool canMovePlayer(Cell* cell);
		void resetCurCell(Cell* cell, char symbol);
		// void floodChamber(int i, int j, std::string (*rows)[MAX_ROW], std::vector<Tile *> *tiles);
		Chamber *getRandomChamber();
		// Tile *getRandomTile();
};
#endif
