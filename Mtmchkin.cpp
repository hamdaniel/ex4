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
using std::unique_ptr;
using std::vector;

const int MAXNAMELENGTH = 15;
const int MAXLINELEN = 9;
const int CARDTYPES = 8;
const int CLASSTYPES = 3;
const int MINDECKSIZE = 5;
const int PLAYERMAXLEVEL = 10;

const string CARDS[CARDTYPES] = {"Goblin", "Vampire", "Dragon", "Barfight", "Pitfall", "Fairy", "Merchant", "Treasure"};
enum class cardType {Goblin, Vampire, Dragon, Barfight, Pitfall, Fairy, Merchant, Treasure};

const string CLASSES[CLASSTYPES] = {"Rogue", "Wizard", "Fighter"};
enum class classType {Rogue, Wizard, Fighter};

static vector<string> readFromFile(string fileName);
static bool isRealCard(string card);
static void initializeLine(char* line);
static string getPlayerName();
static string getPlayerClass();
static bool isValidClass(const string playerClass);
static unique_ptr<Player> createPlayer(const string playerName, const string playerClass);
static bool isActive(const Player& player);
//static void rearrangeWin(vector<unique_ptr<Player>> players, int i);
//static void rearrangeLoss(vector<unique_ptr<Player>> players, int i);

//static string getName();

Mtmchkin::Mtmchkin(const std::string fileName) : m_numRounds(0), m_deck(nullptr), m_players(nullptr), m_leaderboard(nullptr) {
    map <string, shared_ptr<Card>> cards;
    cards[CARDS[(int) cardType::Goblin]] = shared_ptr<Card>(new Goblin(CARDS[(int) cardType::Goblin]));
    cards[CARDS[(int) cardType::Vampire]] = shared_ptr<Card>(new Vampire(CARDS[(int) cardType::Vampire]));
    cards[CARDS[(int) cardType::Dragon]] = shared_ptr<Card>(new Dragon(CARDS[(int) cardType::Dragon]));
    cards[CARDS[(int) cardType::Barfight]] = shared_ptr<Card>(new Barfight(CARDS[(int) cardType::Barfight]));
    cards[CARDS[(int) cardType::Pitfall]] = shared_ptr<Card>(new Pitfall(CARDS[(int) cardType::Pitfall]));
    cards[CARDS[(int) cardType::Fairy]] = shared_ptr<Card>(new Fairy(CARDS[(int) cardType::Fairy]));
    cards[CARDS[(int) cardType::Merchant]] = shared_ptr<Card>(new Merchant(CARDS[(int) cardType::Merchant]));
    cards[CARDS[(int) cardType::Treasure]] = shared_ptr<Card>(new Treasure(CARDS[(int) cardType::Treasure]));

    vector <string> deck = readFromFile(fileName);
    m_numRounds=0;
    for (int i = 0; i < (int) deck.size(); i++) {
        shared_ptr <Card> card = cards[deck[i]];
        m_deck.push(card);
    }
    string numPlayers = "";
    printEnterTeamSizeMessage();
    std::getline(cin, numPlayers, '\n');
    while (std::stoi(numPlayers) < 2 || std::stoi(numPlayers) > 6) {
        printInvalidTeamSize();
        std::getline(cin, numPlayers, '\n');
    }

    int i = 0;
    while (i < std::stoi(numPlayers)) {
        string playerName = getPlayerName();
        string playerClass = getPlayerClass();
        if (isValidClass(playerClass)) {
            m_players.push_back(createPlayer(playerName, playerClass));
            i++;
        } else {
            printInvalidClass();
        }
    }
}

void Mtmchkin::playRound()
{
    for(int i=0; i<(int)m_players.size(); i++){
        if(isActive(*(m_players[i].get())))
        {
            (m_deck.front().get())->applyEncounter(*(m_players[i].get()));
            m_deck.push(m_deck.front());
            m_deck.pop();
            if((m_players[i].get())->getLevel()==PLAYERMAXLEVEL){
                unique_ptr<Player> temp = std::move(m_players[i]);
                for(int j=0; j<i; j++){
                    if(isActive(*(m_players[j].get()))){
                        for(int h=i; h>=j; h--){
                            m_players[h] = std::move(m_players[h-1]);
                        }
                        m_players[j] = std::move(temp);
                        break;
                    }
                }
            }
            if((m_players[i].get())->isKnockedOut()){
                unique_ptr<Player> temp = std::move(m_players[i]);
                for(int j=(int)m_players.size(); j>i; j--){
                    if(isActive(*(m_players[j].get()))){
                        for(int h=i; h<=j; h++){
                            m_players[h] = std::move(m_players[h+1]);
                        }
                        m_players[j] = std::move(temp);
                        break;
                    }
                }
            }
        }
    }
    m_numRounds++;
}

int Mtmchkin::getNumberOfRounds() const
{
    return m_numRounds;
}

void Mtmchkin::printLeaderBoard() const
{
    for(int i=0; i<(int)m_players.size(); i++){
        cout<<*(m_players[i].get())<<endl;
    }
}

bool Mtmchkin::isGameOver() const{
    for(int i=0; i<(int)m_players.size(); i++){
        if(isActive(*(m_players[i].get())))
            return false;
    }
    return true;
}
        //get job
//        m_players = vector<unique_ptr<Player>>; I think it was initialized
//        string currJob;
//        cin.getline(currJob, MAXNAMELENGTH, '\n');
//        while (currJob != "Rouge" && currJob != "Wizard" && currJob != "Fighter") {
//            printInvalidClass();
//            playerName = getName();
//            cin.getline(currJob, MAXNAMELENGTH, '\n');
//        }
//        if (currJob == "Rouge") {
//            std::unique_ptr <Player> ptr(new Rouge(currName));
//            vec.push_back(std::move(ptr));
//        } else if (currJob == "Wizard") {
//            std::unique_ptr <Player> ptr(new Wizard(currName));
//            vec.push_back(std::move(ptr));
//        } else if (currJob == "Fighter") {
//            std::unique_ptr <Player> ptr(new Fighter(currName));
//            vec.push_back(std::move(ptr));
//        }
//    }


static vector<string> readFromFile(string fileName)
{
    ifstream deck(fileName);
    if (!deck){
        throw DeckFileNotFound();
    }
    vector<string> result;
    int currLine = 1;
    char line[MAXLINELEN];
    initializeLine(line);
    while (deck.getline(line, MAXLINELEN, '\n')){
        int lineLen = 0;
        while (line[lineLen]){
            lineLen++;
        }
        string cardName(line, lineLen);
        if (isRealCard(cardName)){
            result.push_back(cardName);
        }
        else{
            throw DeckFileFormatError(currLine);
        }
        initializeLine(line);
        currLine++;
    }
    if((int)result.size()<MINDECKSIZE){
        throw DeckFileInvalidSize();
    }
    return result;
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

static void initializeLine(char* line)
{
    for(int i=0; i<MAXLINELEN; i++){
        line[i]='\0';
    }
}

static string getPlayerName(){
    string result;
    bool flag = true;
    printInsertPlayerMessage();
    while(flag){
        std::getline(cin,result,' ');
        flag=false;
        if(result.size()>15){
            flag=true;
        }
        for(int i=0;i<(int)result.size(); i++){
            if(std::isalpha(result[i])){
                flag=true;
            }
        }
        if(flag){
            printInvalidName();
            std::getline(cin,result,'\n');
        }
    }
    return result;
}

static string getPlayerClass()
{
    string result;
    std::getline(cin,result,'\n');
    return result;
}

static bool isValidClass(string playerClass)
{
    for(int i = 0; i < CLASSTYPES; i++){
        if(!playerClass.compare(CLASSES[i])){
            return true;
        }
    }
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

static bool isActive(const Player& player)
{
    return (!player.isKnockedOut()||player.getLevel()!=PLAYERMAXLEVEL) ? true : false;
}

//static void rearrangeWin(vector<unique_ptr<Player>> players, int i)
//{
//
//}
//
//static void rearrangeLoss(vector<unique_ptr<Player>> players, int i)
//{
//
//}
//static string getName(){
//    string currName;
//    char space=0;
//    printInsertPlayerMessage();
////    cin.getline(currName,MAXNAMELENGTH,' ');
//    getline(cin,currName,' ');
//    std::regex expression([^a-zA-Z]);
//    cin.getline(space,1);
//    while(space!=' ' || !std::regex_search(currName,expression)){
//        printInvalidName();
////        cin.getline(currName,MAXNAMELENGTH,' ');
//        getline(cin,currName,' ');
//        getline(cin,space)
//        cin.getline(space,1);
//    }
//    return currName;
//}