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
using std::unique_ptr;

const string GANG_NAME = "Gang";
const string DRAGON = "Dragon";
const string VAMPIRE = "Vampire";
const string GOBLIN = "Goblin";
const string END_GANG = "EndGang";

Gang::Gang(const vector<string>& monsters):Card(GANG_NAME)
{
    for(unsigned int i = 0; i < monsters.size(); i++){
        if(!monsters[i].compare(DRAGON)){
            m_monsters.push_back(unique_ptr<Battle>(new Dragon()));
        }
        else if(!monsters[i].compare(VAMPIRE)){
            m_monsters.push_back(unique_ptr<Battle>(new Vampire()));
        }
        else{
            m_monsters.push_back(unique_ptr<Battle>(new Goblin()));
        }
    }
}

Gang(const Gang& other)
{
    m_name = GANG_NAME;
    for(unsigned int i = 0; i < other.m_monsters.size(); i++){
        if(!other.m_monsters[i].getName().compare(DRAGON)){
            this.m_monsters.Push_back(unique_ptr<Battle>(new Dragon()));
        }
        else if(!other.m_monsters[i].getName().compare(VAMPIRE)){
            this.m_monsters.Push_back(unique_ptr<Battle>(new Vampire()));
        }
        else{
            this.m_monsters.Push_back(unique_ptr<Battle>(new Goblin()));
        }
    }
}

bool Gang::applyEncounter(Player &player)
{
    for(unsigned int i = 0; i < m_monsters.size(); i++){
        if(!m_monsters[i].get()->applyEncounter(player)){
            for(unsigned int j = i + 1; j < m_monsters.size(); j++){
                m_monsters[j].get()->badNews(player);
            }
            return false;
        }
    }
    return true;
}