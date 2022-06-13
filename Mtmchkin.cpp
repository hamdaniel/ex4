//
// Created by Daniel Hamzany on 13/06/2022.
//

#include "Mtmchkin.h"
#include "utilities.h"
#include "Players/player.h"
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
enum class cardType {goblin, vampire, dragon, barfight, pitfall, fairy, merchant, treasure};
map<string,shared_ptr<Card>> cards;
cards[CARDTYPES[cardType::goblin]] = shared_ptr<Card>(new Goblin("Goblin"));
Mtmchkin::Mtmchkin(const std::string fileName)
{
    ifstream deck(fileName);
    if(!deck){
        throw DeckFileFormatError();
    }
    int currLine=1;
    char line[MAXLINELEN]="";
    while(deck.getline(line,MAXLINELEN,'\n')){
        int lineLen=0;
        while(line[lineLen]){
            lineLen++;
        }
        string cardName(line,lineLen);

    }
}

int main(){
    return 0;
}
