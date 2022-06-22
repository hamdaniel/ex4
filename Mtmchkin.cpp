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
#include "Cards/Gang.h"
#include "Exception.h"
#include <queue>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <regex>
#include <memory>

using std::string;

using std::ifstream;

using std::cout;
using std::cin;
using std::endl;

using std::vector;
using std::queue;
using std::map;

using std::shared_ptr;
using std::unique_ptr;

const int MAX_NAME_LENGTH = 15;
const int PLAYER_MAX_LEVEL = 10;
const int CARD_TYPES = 8;
const int MIN_DECK_SIZE = 5;
const int CLASS_TYPES = 3;

const string GANG = "Gang";
const string GANG_END = "EndGang";

const char* CARDS[CARD_TYPES] =
        {"Goblin", "Vampire", "Dragon", "Barfight", "Pitfall", "Fairy", "Merchant", "Treasure"};
enum class cardType {Goblin, Vampire, Dragon, Barfight, Pitfall, Fairy, Merchant, Treasure};

const string CLASSES[CLASS_TYPES] =
        {"Rogue", "Wizard", "Fighter"};
enum class classType {Rogue, Wizard, Fighter};

static map<string,shared_ptr<Card>> initializeMap();
static vector<shared_ptr<Card>> readFromFile(string fileName, map<string,shared_ptr<Card>> cardsMap);
static bool isRealCard(string card);
static vector<string> buildGang(ifstream& deck, map<string, shared_ptr<Card>> cardsMap, int linenum);
static bool isMonster(string line);

static int getNumPlayers();
static bool isValidNumPlayers(string numPlayers);
static string getPlayerName();
static bool isValidName(const string playerName);
static string getPlayerClass();
static bool isValidClass(const string playerClass);
static unique_ptr<Player> createPlayer(const string playerName, const string playerClass);

static bool isActive(const Player& player);
static void rearrangeWin(vector<unique_ptr<Player>>& players, int winner);
static void rearrangeLoss(vector<unique_ptr<Player>>& players, int loser);



///******************************************Mtmchkin member functions******************************************///
Mtmchkin::Mtmchkin(const std::string fileName) : m_numRounds(0){
    printStartGameMessage();
    map<string, shared_ptr<Card>> cardsMap = initializeMap();
    vector<shared_ptr<Card>> deck = readFromFile(fileName, cardsMap);
    for(int i = 0; i < (int) deck.size(); i++){
        m_deck.push(deck[i]);
    }
    int numPlayers=getNumPlayers();
    for(int i = 0; i < numPlayers; i++){
        printInsertPlayerMessage();
        string playerName = getPlayerName();
        string playerClass = getPlayerClass();
        while((!isValidName(playerName)) || (!isValidClass(playerClass))){
            playerName = getPlayerName();
            playerClass = getPlayerClass();
        }
        m_players.push_back(createPlayer(playerName, playerClass));
    }

}

void Mtmchkin::playRound()
{
    printRoundStartMessage(getNumberOfRounds() + 1);
    for(int i = 0; i < (int)m_players.size(); i++){
        if(isActive(*m_players[i].get())){
            printTurnStartMessage((m_players[i].get())->getName());
            if((m_deck.front().get())->applyEncounter(*(m_players[i].get()))){
                printWinBattle(m_players[i].get()->getName(), m_deck.front().get()->getName());
                (m_players[i].get())->levelUp();
            }
            m_deck.push(m_deck.front());
            m_deck.pop();
            if((m_players[i].get())->getLevel()==PLAYER_MAX_LEVEL){
                rearrangeWin(m_players, i);
            }
            else if((m_players[i].get())->isKnockedOut()){
                rearrangeLoss(m_players, i);
                i--;
            }
        }
    }
    m_numRounds++;
    if(isGameOver()){
        printGameEndMessage();
    }
}

void Mtmchkin::printLeaderBoard() const
{
    printLeaderBoardStartMessage();
    for(int i=0; i<(int)m_players.size(); i++){
        printPlayerLeaderBoard(i + 1, *m_players[i].get());
    }
}

bool Mtmchkin::isGameOver() const{
    for(int i = 0; i < (int)m_players.size(); i++){
        if(isActive(*(m_players[i].get())))
            return false;
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numRounds;
}

///******************************************Mtmchkin C'tor functions******************************************///

///*****************************************Deck helper functions******************************************///
static map<string,shared_ptr<Card>> initializeMap()
{
    map<string,shared_ptr<Card>> cardsMap;
    cardsMap[CARDS[(int) cardType::Goblin]] = shared_ptr<Card>(new Goblin());
    cardsMap[CARDS[(int) cardType::Vampire]] = shared_ptr<Card>(new Vampire());
    cardsMap[CARDS[(int) cardType::Dragon]] = shared_ptr<Card>(new Dragon());
    cardsMap[CARDS[(int) cardType::Barfight]] = shared_ptr<Card>(new Barfight());
    cardsMap[CARDS[(int) cardType::Pitfall]] = shared_ptr<Card>(new Pitfall());
    cardsMap[CARDS[(int) cardType::Fairy]] = shared_ptr<Card>(new Fairy());
    cardsMap[CARDS[(int) cardType::Merchant]] = shared_ptr<Card>(new Merchant());
    cardsMap[CARDS[(int) cardType::Treasure]] = shared_ptr<Card>(new Treasure());
    return cardsMap;
}

static vector<shared_ptr<Card>> readFromFile(string fileName, map<string, shared_ptr<Card>> cardsMap)
{
    ifstream deck(fileName);
    if (!deck){
        throw DeckFileNotFound();
    }
    vector<shared_ptr<Card>> result;
    int currLine = 1;
    string line;
    while (std::getline(deck, line)){
        if (isRealCard(line)){
            result.push_back(cardsMap[line]);
        }
        else if(!line.compare(GANG)) {
            vector<string> gangMembers = buildGang(deck, cardsMap, currLine + 1);
            result.push_back(shared_ptr<Card>(new Gang(gangMembers)));
            currLine += ((int)gangMembers.size() + 1);
        }
        else{
            throw DeckFileFormatError(currLine);
        }
        currLine++;
    }
    if((int)result.size()<MIN_DECK_SIZE){
        throw DeckFileInvalidSize();
    }
    return result;
}

static bool isRealCard(string card)
{
    for(int i = 0; i < CARD_TYPES; i++){
        if(card.compare(CARDS[i]) == 0){
            return true;
        }
    }
    return false;
}

static vector<string> buildGang(ifstream& deck, map<string, shared_ptr<Card>> cardsMap, int linenum)
{
    string line;
    vector<string> result;
    while(std::getline(deck, line)){
        if(!line.compare(GANG_END)){
            for(int i = 0; i < (int)result.size(); i++){
            }
            return result;
        }
        else if(isMonster(line)){
            result.push_back(line);
        }
        else{
            throw DeckFileFormatError(linenum);
        }
        linenum++;
    }
    throw DeckFileFormatError(linenum);
}

static bool isMonster(string line)
{
    if((!line.compare(CARDS[(int)cardType::Dragon])) || (!line.compare(CARDS[(int)cardType::Goblin]))
       || (!line.compare(CARDS[(int)cardType::Vampire]))){
        return true;
    }
    return false;
}


///****************************************Players helper functions****************************************///
static int getNumPlayers()
{
    string numPlayers = "";
    printEnterTeamSizeMessage();
    if(!std::getline(cin,numPlayers)){
        throw InvalidInput();
    }
    while(!isValidNumPlayers(numPlayers)){
        printInvalidTeamSize();
        printEnterTeamSizeMessage();
        if(!std::getline(cin,numPlayers)){
            throw InvalidInput();
        }
    }
    return std::stoi(numPlayers);
}

static bool isValidNumPlayers(string numPlayers)
{
    if(numPlayers.size()!=1){
        return false;
    }
    if(!std::isdigit(numPlayers[0])){
        return false;
    }
    if(std::stoi(numPlayers)<2||std::stoi(numPlayers)>6){
        return false;
    }
    return true;
}

static string getPlayerName(){
    string result;
    if(!std::getline(cin, result, ' ')){
        throw InvalidInput();
    }
    return result;
}

static bool isValidName(string playerName)
{
    if(playerName.size() > MAX_NAME_LENGTH){
        printInvalidName();
        return false;
    }
    for(int i = 0; i < (int)playerName.size(); i++){
        if(!std::isalpha(playerName[i])){
            printInvalidName();
            return false;
        }
    }
    return true;
}

static string getPlayerClass()
{
    string result;
    if(!std::getline(cin, result)){
        throw InvalidInput();
    }
    return result;
}

static bool isValidClass(string playerClass)
{
    for(int i = 0; i < CLASS_TYPES; i++){
        if(!playerClass.compare(CLASSES[i])){
            return true;
        }
    }
    printInvalidClass();
    return false;
}

static unique_ptr<Player> createPlayer(string playerName, string playerClass)
{
    if(!playerClass.compare(CLASSES[(int)classType::Rogue])){
        return unique_ptr<Player>(new Rogue(playerName));
    }
    else if(!playerClass.compare(CLASSES[(int)classType::Wizard])){
        return unique_ptr<Player>(new Wizard(playerName));
    }
    else
        return unique_ptr<Player>(new Fighter(playerName));
}




///***************************************Play Round helper functions**************************************///
static bool isActive(const Player& player)
{
    return (!player.isKnockedOut() && player.getLevel() < PLAYER_MAX_LEVEL) ? true : false;
}

static void rearrangeWin(vector<unique_ptr<Player>>& players, int winner)
{
    unique_ptr<Player> temp = std::move(players[winner]);
    int playersMoved = 0;
    for(int j = 0; j < winner; j++){
        if(isActive(*(players[j].get()))){
            playersMoved = winner - j;
            for(int h = winner; h > j; h--){
                players[h] = std::move(players[h - 1]);
            }
            break;
        }
    }
    players[winner - playersMoved] = std::move(temp);
}

static void rearrangeLoss(vector<unique_ptr<Player>>& players, int loser)
{
    unique_ptr<Player> temp = std::move(players[loser]);
    int playersMoved = 0;
    for(int j = (int)players.size() - 1; j > loser; j--){
        if(isActive(*(players[j].get()))){
            playersMoved = j - loser;
            for(int h = loser; h < j; h++){
                players[h] = std::move(players[h + 1]);
            }
            break;
        }
    }
    players[loser + playersMoved] = std::move(temp);
}