#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "cell.h"
#include "../constants.h"

class Chamber;

class Floor {

	public:


		Floor();
		~Floor();
		
		void loadFromFile(std::ifstream *floorStream);
		void displayFloor();
		// void performAction();
		// void resetMoved();
        Cell *getCell(int i, int j);
		void spawnFloor();
	private:
		int locateChamber(int i, int j);
		Cell *map[MAX_ROW][MAX_COLUMN];
		Chamber *chambers[MAX_CHAMBERS];
		void spawnEnemies();
		void spawnPotions();
		void spawnTreasures();
		void spawnPlayers();
		void spawnStairs();
		// void floodChamber(int i, int j, std::string (*rows)[MAX_ROW], std::vector<Tile *> *tiles);
		Chamber *getRandomChamber();
		// Tile *getRandomTile();
};
#endif
