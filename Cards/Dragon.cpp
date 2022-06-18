//
// Created by user on 07/06/2022.
//

#include "Dragon.h"

Dragon::Dragon(string name) : Battle(name,DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_COINS) {}

void Dragon::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force) {
        printWinBattle(player.getName(),m_cardName);
        player.levelUp();
        player.addCoins(m_coins);
        return;
    }
    else{
        printLossBattle(player.getName(),m_cardName);
        while(!player.isKnockedOut()){
            player.damage(m_damage);
        }
        return;
    }
}