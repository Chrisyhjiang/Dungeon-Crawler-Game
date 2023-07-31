#include <sstream>
#include <iostream>
#include <algorithm>
#include "chamberCrawler.h"
#include "commands/commandInterpreter.h"

ChamberCrawler::ChamberCrawler() : freezeEnenmy(false), level(1){}

ChamberCrawler::~ChamberCrawler(){
    delete floor;
    floorStream->close();
    delete floorStream;  
}

void ChamberCrawler::start(string floorFile, bool ignore){
 
    if( floorFile == ""){
        floorLayoutFile = EMPTY_FLOOR_FILE;
        isDefaultFloor = true;
    }else{
        floorLayoutFile = floorFile;
    }
    floorStream = new ifstream(floorLayoutFile);
    if(ignore){
        setGameRace();
    }
   
    loadFloor();
    play();
}

void  ChamberCrawler::setGameRace(){
    cout << "please choose a game race from the following options: \n";
    for(int i = 0; i < 5; i++){
        cout << "enter " << PLAYER_SYM[i] << " for choosing " << PLAYERS[i] << endl;
    }
    string input;
    
    while (true) {
        // remove the leading space
        std::getline(std::cin >> std::ws, input);
        if(input == string(1, SHADE_SYM) || input == string(1, DROW_SYM) || input == string(1, VAMP_SYM) || 
          input == string(1, TROLL_SYM) || input == string(1, GOBLIN_SYM)) {
            break;
        } else if (input == CMD_RESTART) {
            restartGame();
        } else if (input == CMD_EXIT){
            exit(0);
        }else {
            std::cout << "Invalid input. Please enter a valid game race: ";
        }   
    }
    
    switch (input[0]){
        case SHADE_SYM :
            Player::setRace(SHADE);
            break;
        case DROW_SYM :
            Player::setRace(DROW);
            break;
        case VAMP_SYM :
            Player::setRace(VAMPIRE);
            break;
        case TROLL_SYM :
            Player::setRace(TROLL);
            break;
        case GOBLIN_SYM :
            Player::setRace(GOBLIN);
            break;
        default:
            break;
    }
}

void ChamberCrawler::loadFloor(){
    floor = new Floor();
    floor->loadFromFile(floorStream);
    if (isDefaultFloor){
        floor->spawnPlayers();
        floor->spawnFloor();
    }
    floor->displayFloor("Player character has spawned.", level);
}

void ChamberCrawler::goToNextFloor() {
    nextFloor = false;
    level ++;
	if (level > MAX_LEVEL) {
		cout << endl;
		cout << "you beat the game!!!." << endl;
		cout << "Your score is: " << Player::getInstance()->getScore() << endl;
		restartOrQuit();
	} else {
	
        Player* player = Player::getInstance();
        player->setCellSymbol(SYM_TILE);
        player->setAtk(player->getDefaultAtk());
        player->setDef(player->getDefaultDef());
        loadFloor();
	}
}

void ChamberCrawler::restartOrQuit() {
	while (true) {
		cout << "Restart (r) or Quit (q)?" << endl;
		string choice;
		getline(cin, choice);
		if (tolower(choice[0]) == 'r') {
			restart = true;
			break;
		} else if (tolower(choice[0]) == 'q') {
			quit = true;
			break;
		}
	}
    if (restart) {
        restartGame();
    } else {
        cout << "Thanks for playing!!!" << endl;
        exit(0);
    }
}

void ChamberCrawler::restartGame() {
    restart = false;
	level = 1;
    Player::setInstance();
    Merchant::setHostile(false);
	start(floorLayoutFile, true);
	Player::getInstance()->setCellSymbol(SYM_TILE);
}

void ChamberCrawler::play(){
   while(true){
        string actionMsg = "";
        actionMsg += playerTakeTurn();
        actionMsg += enemiesTakeTurn();
        Player* player = Player::getInstance();
        if (player->isDead()) {
            floor->displayFloor(actionMsg, level);
            cout << "You Died!" << endl; // Do you want to restart the game? [y/n]" << endl;
            restartOrQuit();
        } else {
            if(player->getCellSymbol() == SYM_STAIRS){
               if(!isDefaultFloor){
                    goToNextFloor();
               }else {
                    level++;
                    if (level == 6) {
                    cout << "you beat the game!!!" << endl;
                    int g = player->getGold();
                    if (player->getRace() == "shade") {
                        g *= 1.5;
                    }
                    cout << "your score for this round is " << g << endl;
                    exit(0);
                    }
                start("", false);
                player->setCellSymbol(SYM_TILE);
                player->setAtk(player->getDefaultAtk());
                player->setDef(player->getDefaultDef());
               }
                
            }else{
                floor->displayFloor(actionMsg, level);
            }
        }
    }
}

Floor* ChamberCrawler::getFloor(){
    return floor;
}

string ChamberCrawler::playerTakeTurn(){
    string msg = "";
    while(true){
        cout << "enter a valid command: " ;
        string line;
        std::getline(std::cin, line);
        // CommandInterpreter* ci = new CommandInterpreter(this);
        CommandInterpreter ci(this);
        msg = ci.executeCommand(line);
        if(msg != ""){
            if(msg == CMD_EXIT){
                exit(0);
            }else{
                break;
            }
        }else {
            cout << "invalid command ...." << endl;
        }
        //delete ci;
    }
    return msg;
}

bool ChamberCrawler::getFreezeEnemy(){
    return freezeEnenmy;
}

void ChamberCrawler::setFreezeEnemy(bool freeze){
    freezeEnenmy = freeze;
}

string ChamberCrawler::enemiesTakeTurn(){
    string result = "";
    if(!freezeEnenmy){
        vector<string> msg = floor->enemyTurn();
        if(msg.size() != 0){
            result = "Action: Enemy ";
            for(string s : msg){
                result += s;
                result += " | ";
            }
        }
    }
    return result;
}