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

Battle::Battle(const string name, const int force, const int damage, const int coins)  :
                                                             Card(name),
                                                             m_force(force),
                                                             m_damage(damage),
                                                             m_loot(coins) {}

void Battle::printCardInfo(ostream& os) const
{
    printCardDetails(os, this->getName());
    bool isDragon = (!(this->getName().compare(DRAGON))) ? true : false;
    printMonsterDetails(os, this->m_force, this->m_damage, this->m_loot, isDragon);
    printEndOfCardDetails(os);
}

bool Battle::applyEncounter(Player& player)
{
    if (player.getAttackStrength() >= m_force) {
        player.addCoins(m_loot);
        return true;
    }
    else{
        badNews(player);
        return false;
    }
}

void Battle::badNews(Player &player)
{
    printLossBattle(player.getName(), getName());
    player.damage(m_damage);
}