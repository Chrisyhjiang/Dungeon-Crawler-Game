#include <sstream>
#include <iostream>
#include <algorithm>
#include "chamberCrawler.h"

ChamberCrawler::ChamberCrawler() : canEnemyTakeTurn(true){}

ChamberCrawler::~ChamberCrawler(){
    delete floor;
    floorStream->close();
    delete floorStream;  
}

// void ChamberCrawler::start(string floorFile){
 
//     if( floorFile == ""){
//         floorLayoutFile = EMPTY_FLOOR_FILE;
//         isDefaultFloor = true;
//     }else{
//         floorLayoutFile = floorFile;
//     }
//     floorStream = new ifstream(floorLayoutFile);
//     setGameRace();
//     loadFloor();
//     play();
// }

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
    char input;
    
    while (true) {
        cin >> input;
        if(input == SHADE_SYM || input == DROW_SYM || input == VAMP_SYM || input == TROLL_SYM || input == GOBLIN_SYM) {
            break;
        } else if (std::string(1, input) == CMD_RESTART) {
            restartGame();
        }else {
            std::cout << "Invalid input. Please enter a valid game race: " << endl;
        }   
    }
    
    switch (input){
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
    floor->displayFloor("Player character has spawned.");
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
		// Carry over stats for next floor.
		// Player *player = Player::getInstance()->getBarePlayer();
		// Player::setInstance(player);
        Player* player = Player::getInstance();
        player->setCellSymbol(SYM_TILE);
        player->setAtk(player->getDefaultAtk());
        player->setDef(player->getDefaultDef());
        //delete floor;
        loadFloor();
	}
   
}

void ChamberCrawler::restartOrQuit() {
	string r;
	getline(cin, r);
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
}


void ChamberCrawler::restartGame() {
    restart = false;
	// delete floor;
	// delete floorStream;
	level = 1;
    Player::setInstance();
	Player::getInstance()->setCellSymbol(SYM_TILE);
	start(floorLayoutFile, true);
}


void ChamberCrawler::play(){
   while(true){
        // if(nextFloor){
        //     goToNextFloor();
        // }
        // if (restart){
        //     restart = false;
        //     restartGame();
        // }
        // if(quit){
        //     cout << "Thank You for playing..." << endl;
        // }

        string actionMsg = "";
        actionMsg += playerTakeTurn();
        if(canEnemyTakeTurn){
            actionMsg +=enemiesTakeTurn();
        }
       
        Player* player = Player::getInstance();
        if (player->isDead()) {
            floor->displayFloor(actionMsg);
            cout << "You Died!" << endl; // Do you want to restart the game? [y/n]" << endl;
            restartOrQuit();
            // string x; 
            // while (true) {
            //     cin >> x;
            //     if (x == "y") {
            //         restartGame();
            //     } else if (x == "n") {
            //          cout << "Thank You for playing..." << endl;
            //          exit(0);
            //     } else {
            //         cout << "Please input [y/n]" << endl;
            //     }
            // }
            if (restart) {
                restartGame();
            } else {
                cout << "Thanks for playing!!!" << endl;
                exit(0);
            }
        } else {
            if(player->getCellSymbol() == SYM_STAIRS){
               // goToNextFloor();
               if(!isDefaultFloor){
                    goToNextFloor();
               }else {
                    if (floor->getLevel() == 5) {
                    cout << "you beat the game!!!" << endl;
                    int g = player->getGold();
                    if (player->getRace() == "shade") {
                        g *= 1.5;
                    }
                    cout << "your score for this round is " << g << endl;
                    exit(0);
                    }
                start("", false);
                floor->setLevel(floor->getLevel() + 1);
                player->setCellSymbol(SYM_TILE);
                player->setAtk(player->getDefaultAtk());
                player->setDef(player->getDefaultDef());
               }
                
            }else{
                floor->displayFloor(actionMsg);
            }
        }
    }
}

string ChamberCrawler::playerTakeTurn(){
    string msg = "";
    while(true){
        cout << "enter a valid command: " ;
        string cmd;
        cin >> cmd;
        if(isValidCmd(cmd)){
            Troll *t = dynamic_cast<Troll*>(Player::getInstance());
            if (t) {
                t->setHP(min(t->getMaxHp(), t->getHP() + 5));
            }
            if (cmd == CMD_ATTACK){
                string dir;
                cin >> dir;
                if(isValidCmd(dir)){
                    msg = processPlayerAttackCmd(dir);
                    if(msg.size() > 0){
                        break;
                    }else {
                         cout << "invalid command: no enemy to be attacked !!!" << endl; 
                    }
                }else{
                    cout << "invalid command: direction is invalid" << endl;
                } 
               
            } else if (cmd == CMD_POTION){
                string dir;
                cin >> dir;
                if(isValidCmd(dir)){
                    msg = processPlayerUsePotionCmd(dir);
                    if(msg.size() > 0){
                        break;
                    }else{
                         cout << "invalid command: no potion !!!" << endl; 
                    }
                }
                break;
            } else if ( cmd == CMD_EXIT){
                exit(0);
            }else if ( cmd == CMD_RESTART) {
                restartGame();
            } else if ( cmd == CMD_FREEZE) {
                canEnemyTakeTurn = !canEnemyTakeTurn;
            } else {
                msg = floor->movePlayer(cmd);
                if(msg.size() > 0){
                    break;
                }else{
                    cout << "invalid command: direction is not valid" << endl;
                }
            }
        }else {
            cout << "command:" << cmd << " is invalid " << endl;
        }
    }
    return msg;
}

string ChamberCrawler::processPlayerAttackCmd(string direction){
    string actionMsg = "";
    Enemy* enemy = floor->canPlayerAttack(direction);
    if(enemy){
        Merchant* m = dynamic_cast<Merchant*>(enemy);
        if (m) {
            Merchant::setHostile();
        }
        Player* player = Player::getInstance();
        int HP = enemy->getHP();
        int damage = player->calculateDmgToEnemy(enemy->getDef());
        // enemy->takeDamage(damage);
        player->attackEnemy(enemy);
        if(Player::getRace() == TROLL && player->getHP() < player->getDefaultHP()){
            actionMsg += "Player gain HP | ";
        }
        
        actionMsg += "Player attacked Enemy " + string(1, enemy->getSymbol()) + " (HP) " + to_string(enemy->getHP());
        
        if(enemy->getSymbol() == ENEMY_HALFING && HP == enemy->getHP()){
            actionMsg += " player missed attack (HALFING)...\n";

        }else{
            actionMsg += " | enemy take damage: " + to_string(damage) + "\n";
        }
        
      

    }
    return actionMsg;
}
                
string ChamberCrawler::processPlayerUsePotionCmd(string dir){
    string actionMsg = "";
    ItemDecorator* potion = floor->canPlayerTakePotion(dir);
    if(potion){
        potion->update();
        actionMsg = "Player take potion: " + potion->getName() + "\n";
    }
    return actionMsg;
}

bool ChamberCrawler::isValidCmd(string cmd){
    if ( cmd == CMD_ATTACK || cmd == CMD_POTION || cmd == CMD_EXIT || cmd == CMD_RESTART || cmd == CMD_FREEZE){
        return true;
    }
    auto it = find(std::begin(DIRECTIONS), end(DIRECTIONS), cmd);
    return it != end(DIRECTIONS);
}

string ChamberCrawler::enemiesTakeTurn(){
    vector<string> msg = floor->enemyTurn();
    string result = "Action: Enemy ";
    if(msg.size() == 0){
        result += "take move randomly...";

    }else {
        for(string s : msg){
            result += s;
            result += " | ";
        }
    }
    return result;
}

