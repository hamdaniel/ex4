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
const string END_GANG = "EndGang";

const char* CARDS[CARD_TYPES] =
        {"Goblin", "Vampire", "Dragon", "Barfight", "Pitfall", "Fairy", "Merchant", "Treasure"};
enum class CardType {Goblin, Vampire, Dragon, Barfight, Pitfall, Fairy, Merchant, Treasure};

const string CLASSES[CLASS_TYPES] =
        {"Rogue", "Wizard", "Fighter"};
enum class classType {Rogue, Wizard, Fighter};

static vector<string> readFromFile(string fileName);
static bool isRealCard(string card);
static bool isValidGang(ifstream& deck, string line, vector<string>& result, int& lineNum);
static bool isMonster(string line);

static int getNumPlayers();
static bool isValidNumPlayers(string numPlayers);
static string getPlayerName();
static bool isValidName(const string playerName);
static string getPlayerClass();
static bool isValidClass(const string playerClass);
static unique_ptr<Player> createPlayer(const string playerName, const string playerClass);

static bool isActive(const Player& player);
static void rearrangeOnWin(vector<unique_ptr<Player>>& players, int winner);
static void rearrangeOnLoss(vector<unique_ptr<Player>>& players, int loser);



///******************************************Mtmchkin member functions******************************************///
Mtmchkin::Mtmchkin(const std::string fileName) : m_numRounds(0){
    printStartGameMessage();
    vector<string> deck = readFromFile(fileName);
    for(unsigned int i=0;i<deck.size();i++){
    }
    initializeDeck(deck);
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
    for(unsigned int i = 0; i < m_players.size(); i++){
        if(isActive(*m_players[i].get())){
            printTurnStartMessage((m_players[i].get())->getName());
            if((m_deck.front().get())->applyEncounter(*(m_players[i].get()))){
                printWinBattle(m_players[i].get()->getName(), m_deck.front().get()->getName());
                (m_players[i].get())->levelUp();
            }
            m_deck.push(std::move(m_deck.front()));
            m_deck.pop();
            if((m_players[i].get())->getLevel()==PLAYER_MAX_LEVEL){
                rearrangeOnWin(m_players, i);
            }
            else if((m_players[i].get())->isKnockedOut()){
                rearrangeOnLoss(m_players, i);
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
    for(unsigned int i=0; i < m_players.size(); i++){
        printPlayerLeaderBoard(i + 1, *m_players[i].get());
    }
}

bool Mtmchkin::isGameOver() const{
    for(unsigned int i = 0; i < m_players.size(); i++){
        if(isActive(*(m_players[i].get())))
            return false;
    }
    return true;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numRounds;
}

void Mtmchkin::initializeDeck(vector<string> deck)
{
    for(unsigned int i = 0; i < deck.size(); i++){
        if(!deck[i].compare(CARDS[(int)CardType::Vampire])){
            m_deck.push(unique_ptr<Card>(new Vampire()));
        }
        else if(!deck[i].compare(CARDS[(int)CardType::Goblin])){
            m_deck.push(unique_ptr<Card>(new Goblin()));
        }
        else if(!deck[i].compare(CARDS[(int)CardType::Dragon])){
            m_deck.push(unique_ptr<Card>(new Dragon()));
        }
        else if(!deck[i].compare(CARDS[(int)CardType::Barfight])){
            m_deck.push(unique_ptr<Card>(new Barfight()));
        }
        else if(!deck[i].compare(CARDS[(int)CardType::Treasure])){
            m_deck.push(unique_ptr<Card>(new Treasure()));
        }
        else if(!deck[i].compare(CARDS[(int)CardType::Pitfall])){
            m_deck.push(unique_ptr<Card>(new Pitfall()));
        }
        else if(!deck[i].compare(CARDS[(int)CardType::Fairy])){
            m_deck.push(unique_ptr<Card>(new Fairy()));
        }
        else if(!deck[i].compare(CARDS[(int)CardType::Merchant])){
            m_deck.push(unique_ptr<Card>(new Merchant()));
        }
        else if(!deck[i].compare(GANG)){
            vector<string> gangsters;
            i++;
            while(deck[i].compare(END_GANG)){
                gangsters.push_back(deck[i]);
                i++;
            }
            m_deck.push(unique_ptr<Card>(new Gang(gangsters)));
        }

    }
}


///******************************************Mtmchkin C'tor functions******************************************///

///*****************************************Deck helper functions******************************************///
static vector<string> readFromFile(string fileName)
{
    ifstream deck(fileName);
    if (!deck){
        throw DeckFileNotFound();
    }
    vector<string> result;
    int currLine = 1;
    int numCards = 0;
    string line;
    while (std::getline(deck, line)){
        if (isRealCard(line)){
            result.push_back(line);
            numCards++;
        }
        else if (!line.compare(GANG)){
            result.push_back(line);
            if(!isValidGang(deck, line, result, currLine)){
                deck.close();
                throw DeckFileFormatError(currLine);
            }
            numCards++;
        }
        else{
            deck.close();
            throw DeckFileFormatError(currLine);
        }
        currLine++;
    }
    if(numCards<MIN_DECK_SIZE){
        deck.close();
        throw DeckFileInvalidSize();
    }
    deck.close();
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

static bool isValidGang(ifstream& deck, string line, vector<string>& result, int& lineNum)
{
    while(std::getline(deck, line)){
        if(!line.compare(END_GANG)){
            result.push_back(END_GANG);
            lineNum++;
            return true;
        }
        else if(!isMonster(line)){
            return false;
        }
        result.push_back(line);
        lineNum++;
    }
    return false;
}

static bool isMonster(string line)
{
    if((!line.compare(CARDS[(int)CardType::Dragon])) || (!line.compare(CARDS[(int)CardType::Goblin]))
       || (!line.compare(CARDS[(int)CardType::Vampire]))){
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
    for(unsigned int i = 0; i < playerName.size(); i++){
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

static void rearrangeOnWin(vector<unique_ptr<Player>>& players, int winner)
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

static void rearrangeOnLoss(vector<unique_ptr<Player>>& players, int loser)
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