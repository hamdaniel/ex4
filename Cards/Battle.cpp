//
// Created by user on 07/06/2022.
//

#include "Battle.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include <string>

using std::string;
using std::ostream;
const string DRAGON = "Dragon";

Battle::Battle(string name, int force, int damage, int coins):
                                                             Card(name),
                                                             m_force(force),
                                                             m_damage(damage),
                                                             m_loot(coins) {}

void Battle::printCardInfo(ostream& os) const
{
    printCardDetails(os, this->getName());
    bool isDragon = ((this->getName().compare(DRAGON)))?true:false;
    printMonsterDetails(os,this->m_force,this->m_damage,this->m_loot, isDragon);
    printEndOfCardDetails(os);
}