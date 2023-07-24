#ifndef ___CHAMBERCRAWLER_H___
#define ___CHAMBERCRAWLER_H___

#include <string>
#include <fstream>
#include <vector>
#include "./floors/floor.h"
#include "./players/player.h"
#include "./players/playerFactory.h"

using namespace std;
 
class ChamberCrawler {
	private:
		string floorLayoutFile;
		ifstream *floorStream;
		Player* player;
		Floor* floor;
		static string race;

	public:
		ChamberCrawler();
		~ChamberCrawler();
		static void setGameRace();
		static string getRace();
		void start(string floorFile);
		void loadFloor(Player* player);

		//void displayFloor();
};
#endif
