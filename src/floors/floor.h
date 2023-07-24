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
		Floor();
		~Floor();
		
		void loadFromFile(std::ifstream *floorStream);
		void displayFloor();
        Cell *getCell(int i, int j);
		void spawnFloor(Player* player);
		void spawnPlayers(Player* player);

	private:
		int locateChamber(int i, int j);
		Cell* cells[MAX_ROW][MAX_COLUMN];
		Chamber* chambers[MAX_CHAMBERS];
		void spawnEnemies();
		void spawnPotions(Player* player);
		void spawnTreasures(Player* player);
		void spawnStairs();
		// void floodChamber(int i, int j, std::string (*rows)[MAX_ROW], std::vector<Tile *> *tiles);
		Chamber *getRandomChamber();
		// Tile *getRandomTile();
};
#endif
