//
// Created by Daniel Hamzany on 21/06/2022.
//

#include "Gang.h"
#include "Card.h"
#include "Battle.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include <vector>
#include <string>
#include <memory>

using std::string;
using std::vector;
using std::shared_ptr;

const string GANG_NAME = "Gang";
const string DRAGON = "Dragon";
const string VAMPIRE = "Vampire";
const string GOBLIN = "Goblin";


Gang::Gang(vector<string>& monsters):Card(GANG_NAME)
{
    for(int i = 0; i < (int)monsters.size(); i++){
        if(!monsters[i].compare(DRAGON)){
            m_monsters.push_back(shared_ptr<Battle>(new Dragon()));
        }
        else if(!monsters[i].compare(VAMPIRE)){
            m_monsters.push_back(shared_ptr<Battle>(new Vampire()));
        }
        else{
            m_monsters.push_back(shared_ptr<Battle>(new Goblin()));
        }
    }
}

bool Gang::applyEncounter(Player &player)
{
    for(int i = 0; i < (int)m_monsters.size(); i++){
        if(!m_monsters[i].get()->applyEncounter(player)){
            for(int j = i + 1; j < (int)m_monsters.size(); j++){
                m_monsters[j].get()->badNews(player);
            }
            return false;
        }
    }
    return true;
}