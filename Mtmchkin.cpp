//
// Created by Daniel Hamzany on 13/06/2022.
//

#include "Mtmchkin.h"
#include "utilities.h"
#include "Players/Player.h"
#include "Players/Fighter.h"
#include "Players/Rogue.h"
#include "Players/Wizard.h"
#include "Cards/Card.h"
#include "Cards/Battle.h"
#include "Cards/Goblin.h"
#include "Cards/Vampire.h"
#include "Cards/Dragon.h"
#include "Cards/Fairy.h"
#include "Cards/Barfight.h"
#include "Cards/Pitfall.h"
#include "Cards/Treasure.h"
#include "Cards/Merchant.h"
#include "Exception.h"
#include <queue>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include <regex>

using std::string;
using std::ifstream;
using std::cout;
using std::endl;
using std::queue;
using std::map;
using std::shared_ptr;

const int MAXLINELEN=9;
const int CARDTYPES=8;
const string CARDS[CARDTYPES]={"Goblin", "Vampire", "Dragon", "Barfight", "Pitfall", "Fairy", "Merchant", "Treasure"};
enum class cardType {Goblin, Vampire, Dragon, Barfight, Pitfall, Fairy, Merchant, Treasure};

static bool isRealCard(string card);
static void initializeLine(char* line);
static void getName();

Mtmchkin::Mtmchkin(const std::string fileName) {
    map <string, shared_ptr<Card>> cards;
    cards[CARDS[(int) cardType::Goblin]] = shared_ptr<Card>(new Goblin(CARDS[(int) cardType::Goblin]));
    cards[CARDS[(int) cardType::Vampire]] = shared_ptr<Card>(new Vampire(CARDS[(int) cardType::Vampire]));
    cards[CARDS[(int) cardType::Dragon]] = shared_ptr<Card>(new Dragon(CARDS[(int) cardType::Dragon]));
    cards[CARDS[(int) cardType::Barfight]] = shared_ptr<Card>(new Barfight(CARDS[(int) cardType::Barfight]));
    cards[CARDS[(int) cardType::Pitfall]] = shared_ptr<Card>(new Pitfall(CARDS[(int) cardType::Pitfall]));
    cards[CARDS[(int) cardType::Fairy]] = shared_ptr<Card>(new Fairy(CARDS[(int) cardType::Fairy]));
    cards[CARDS[(int) cardType::Merchant]] = shared_ptr<Card>(new Merchant(CARDS[(int) cardType::Merchant]));
    cards[CARDS[(int) cardType::Treasure]] = shared_ptr<Card>(new Treasure(CARDS[(int) cardType::Treasure]));
    ifstream deck(fileName);
    if (!deck) {
        throw DeckFileNotFound();
    }
    int currLine = 1;
    char line[MAXLINELEN];
    initializeLine(line);
    while (deck.getline(line, MAXLINELEN, '\n')) {
        int lineLen = 0;
        while (line[lineLen]) {
            lineLen++;
        }
        string cardName(line, lineLen);
        if (isRealCard(cardName)) {
            shared_ptr <Card> card = cards[cardName];
            m_deck.push(card);
        } else {
            throw DeckFileFormatError(currLine);
        }
        initializeLine(line);
        currLine++;
    }
    //start game and get num players
    printStartGameMessage();
    int numPlayers = 0;
    printEnterTeamSizeMessage();
    cin << numPlayers;
    while (numPlayers != 2 && numPlayers != 3 && numPlayers != 4 && numPlayers != 5 && numPlayers != 6){
        printInvalidTeamSize();
        cin << numPlayers;
    }
    //get name
    getName();
    //get card
    m_players=std::vector<std::unique_ptr<Player>>;
    string currJob;
    cin.getline(currJob,15,'\n');
    while(currJob!="Rouge"&&currJob!="Wizard"&&currJob!="Fighter"){
        printInvalidClass();
        getName();
        cin.getline(currJob,15,'\n');
    }
    if(currJob=="Rouge"){
        std::unique_ptr<Player> ptr(new Rouge(currName));
        vec.push_back(std::move(ptr));
    }
    else if(currJob=="Wizard"){
        std::unique_ptr<Player> ptr(new Wizard(currName));
        vec.push_back(std::move(ptr));
    }
    else if(currJob=="Fighter"){
        std::unique_ptr<Player> ptr(new Fighter(currName));
        vec.push_back(std::move(ptr));
    }
}

static bool isRealCard(string card)
{
    for(int i=0; i<CARDTYPES; i++){
        if(card.compare(CARDS[i])==0){
            return true;
        }
    }
    return false;
}
int main(){
    return 0;
}

static void initializeLine(char* line)
{
    for(int i=0; i<MAXLINELEN; i++){
        line[i]='\0';
    }
}

static void getName(){
    string currName;
    char space=0;
    printInsertPlayerMessage();
    cin.getline(currName,15,' ');
    std::regex expression([^a-zA-Z]);
    cin.getline(space,1);
    while(space!=' ' || !std::regex_search(currName,expression)){
        printInvalidName();
        cin.getline(currName,15,' ');
        cin.getline(space,1);
    }
}