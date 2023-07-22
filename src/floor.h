#ifndef ___FLOOR_H___
#define ___FLOOR_H___
#include <string>
#include <fstream>
#include <vector>

 

class Floor {

	public:
		static const int MAX_CHAMBERS = 5;
		static const int MAX_ROW = 25;
		static const int MAX_COLUMN = 79;
		static const int NUM_GOLD = 10;
		static const int NUM_POTION = 10;
		static const int NUM_ENEMY = 20;

		static char const SYM_PLAYER = '@';
		static char const SYM_WALL_VER = '|';
		static char const SYM_WALL_HOR = '-';
		static char const SYM_DOORWAY = '+';
		static char const SYM_PASSAGE = '#';
		static char const SYM_TILE = '.';
		static char const STAIRS = '\\';

		static char const ENEMY_HUMAN = 'H';
		static char const ENEMY_DWARF = 'W';
		static char const ENEMY_ELF = 'E';
		static char const ENEMY_ORC = 'O';
		static char const ENEMY_MERCHANT = 'M';
		static char const ENEMY_DRAGON = 'D';
		static char const ENEMY_HALFING = 'L';

		static char const GOLD = 'G';
		static char const POTION = 'P';

		Floor();
		~Floor();

		void loadFromFile(std::ifstream *floorStream);
		void displayFloor();
		void performAction();
		void resetMoved();
		void spawn();
        Cell *getCell(int i, int j);
	private:
		Cell *map[MAX_ROW][MAX_COLUMN];
		Chamber *chambers[MAX_CHAMBERS];

		void floodChamber(int i, int j, std::string (*rows)[MAX_ROW], std::vector<Tile *> *tiles);
		Chamber *getRandomChamber();
		Tile *getRandomTile();
};
#endif
