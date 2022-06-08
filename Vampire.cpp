//
// Created by user on 07/06/2022.
//
#include "Vampire.h"
Vampire::Vampire(CardName name)  : Battle(name,VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_COINS) {};

void Vampire::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force) {
        player.levelUp();
        player.addCoins(m_coins);
        return;
    }
    else{
        player.damage(m_damage);
        player.buff(-1);
    }
    return;
}


