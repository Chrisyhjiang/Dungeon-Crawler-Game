#ifndef ___CHAMBERCRAWLER_H___
#define ___CHAMBERCRAWLER_H___

#include <string>
#include <fstream>
#include <vector>
#include "./floors/floor.h"

using namespace std;
 
class ChamberCrawler {
	private:
		string floorLayoutFile;
		ifstream *floorStream;
		 

	public:
		ChamberCrawler();
		~ChamberCrawler();
		void start(string race, string floorFile);
		string chooseGameRace();

};
#endif
