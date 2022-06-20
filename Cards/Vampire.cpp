//
// Created by user on 07/06/2022.
//
#include "Vampire.h"

Vampire::Vampire(string name)  : Battle(name,VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_COINS) {}

void Vampire::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force) {
        printWinBattle(player.getName(),getName());
        player.levelUp();
        player.addCoins(m_coins);
        return;
    }
    else{
        printLossBattle(player.getName(),getName());
        player.damage(m_damage);
        player.buff(VAMPIRE_DEBUFF);
        return;
    }
}


