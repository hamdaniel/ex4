//
// Created by user on 07/06/2022.
//

#include "Dragon.h"
#include "Player.h"

Dragon::Dragon(string name) : Battle(name,DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_COINS) {};

void Dragon::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force) {
        player.levelUp();
        player.addCoins(m_coins);
        return;
    }
    else{
        while(!player.isKnockedOut()){
            player.damage(m_damage);
        }
        return;
    }
}