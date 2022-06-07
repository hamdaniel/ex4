//
// Created by user on 07/06/2022.
//


#include "Dragon.h"
Vampire::Dragon(CardName name) : Battle(name,DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_COINS) {};

bool Dragon::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force){
        player.levelUp();
        player.addCoins(m_coins);
        return true;
    }
    player.damage(m_damage);
    return false;
}