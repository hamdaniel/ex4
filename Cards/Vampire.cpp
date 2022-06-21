//
// Created by user on 07/06/2022.
//
#include "Vampire.h"

using std::string;

const string VAMPIRE_NAME = "Vampire";
const int VAMPIRE_FORCE = 10;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_COINS = 2;
const int VAMPIRE_DEBUFF = -1;

Vampire::Vampire()  : Battle(VAMPIRE_NAME,VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_COINS) {}

void Vampire::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force) {
        printWinBattle(player.getName(),getName());
        player.levelUp();
        player.addCoins(m_loot);
        return;
    }
    else{
        printLossBattle(player.getName(),getName());
        player.damage(m_damage);
        player.buff(VAMPIRE_DEBUFF);
        return;
    }
}


