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

	public:
		ChamberCrawler();
		~ChamberCrawler();
		void start(string race, string floorFile);
		string chooseGameRace();
		void loadFloor();
		//void displayFloor();
};
#endif
