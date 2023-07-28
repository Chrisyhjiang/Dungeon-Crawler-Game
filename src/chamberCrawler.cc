#include <sstream>
#include <iostream>
#include <algorithm>
#include "chamberCrawler.h"

ChamberCrawler::ChamberCrawler(){}

ChamberCrawler::~ChamberCrawler(){
    //Todo:    
}

void ChamberCrawler::start(string floorFile, int level){
    floorLayoutFile =  (floorFile == "") ? EMPTY_FLOOR_FILE : floorFile;
    floorStream = new ifstream(floorLayoutFile);
    loadFloor(level);
    play();
}

void  ChamberCrawler::setGameRace(){
    cout << "please choose a game race from the following options: \n";
    for(int i = 0; i < 5; i++){
        cout << "enter " << i+1 << " for choosing " << PLAYERS[i] << endl;
    }
    std::cout << "Enter an integer between 1 and 5: ";
    string number;
    string input;
    int n = -1;
    while (getline(cin, input)) {
        stringstream ss(input);
        if (ss >> number) {
            try {
                n = stoi(number);
            } catch(...) {
                
            }
            if(n >= 1 && n <= 5) {
                break;
            }
        }  
        std::cout << "Invalid input. Please enter an integer between 1 and 5" << endl;
    }
    
    switch (n){
        case 1 :
            Player::setRace(SHADE);
            break;
        case 2 :
            Player::setRace(DROW);
            break;
        case 3 :
            Player::setRace(VAMPIRE);
            break;
        case 4 :
            Player::setRace(TROLL);
            break;
        case 5 :
            Player::setRace(GOBLIN);
            break;
        default:
            break;
    }

}

void ChamberCrawler::loadFloor(int n){
    floor = new Floor(n);
    floor->loadFromFile(floorStream);
    floor->spawnPlayers();
    floor->spawnFloor();
    floor->displayFloor("");
}

void ChamberCrawler::play(){
   while(true){
        string actionMsg = "";
        actionMsg += playerTakeTurn();
        actionMsg +=enemiesTakeTurn();
        //actionMsg.erase(actionMsg.size() - 1);
        Player* player = Player::getInstance();
        if (player->isDead()) {
            floor->displayFloor(actionMsg);
            cout << "You Died! Do you want to restart the game? [y/n]" << endl;
            string x; 
            while (true) {
                cin >> x;
                if (x == "y") {
                    Player::setInstance();
                    this->start("", 1);
                } else if (x == "n") {
                    exit(0);
                } else {
                    cout << "Please input [y/n]" << endl;
                }
            }
        } else {
            if(player->getCellSymbol() == SYM_STAIRS){
                if (floor->getLevel() == 5) {
                    cout << "you beat the game!!!" << endl;
                    exit(0);
                }
                start("", floor->getLevel()+1);
                player->setAtk(player->getDefaultAtk());
                player->setDef(player->getDefaultDef());
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
            }
            else {
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
        
        actionMsg += "Player attcked Enemy " + string(1, enemy->getSymbol()) + " (HP) " + to_string(enemy->getHP());
        
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
    if ( cmd == CMD_ATTACK || cmd == CMD_POTION || cmd == CMD_EXIT){
        return true;
    }
    auto it = find(std::begin(DIRECTIONS), end(DIRECTIONS), cmd);
    return it != end(DIRECTIONS);
}

string ChamberCrawler::enemiesTakeTurn(){
    vector<string> msg = floor->enemyTurn();
    string result = "Action: Enemy ";
    if(msg.size() == 0){
        result += " take move randomly...";

    }else {
        for(string s : msg){
            result += s;
            result += " | ";
        }
    }
    return result;
}

