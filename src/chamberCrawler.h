#ifndef ___CHAMBERCRAWLER_H___
#define ___CHAMBERCRAWLER_H___

#include <string>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "./floors/floor.h"
#include "./players/player.h"

using namespace std;
 
class ChamberCrawler {
	private:
		string floorLayoutFile;
		ifstream *floorStream;
		Floor* floor;
		void play();
		string playerTakeTurn();
		string enemiesTakeTurn();
		string processPlayerAttackCmd(string direction);
		string processPlayerMoveCmd(string direction);
		string processPlayerUsePotionCmd(string direction);
		bool isValidCmd(string cmd);

	public:
		ChamberCrawler();
		~ChamberCrawler();
		static void setGameRace();
		void start(string floorFile, int level);
		void loadFloor(int level);
		void playGame();
		
};
#endif
