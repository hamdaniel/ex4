//
// Created by user on 07/06/2022.
//

#include "Dragon.h"

using std::string;

const string DRAGON_NAME = "Dragon";
const int DRAGON_FORCE = 25;
const int DRAGON_DAMAGE = DEFAULT_HP;
const int DRAGON_COINS = 1000;

Dragon::Dragon() : Battle(DRAGON_NAME,DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_COINS) {}

void Dragon::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force) {
        printWinBattle(player.getName(),getName());
        player.levelUp();
        player.addCoins(m_loot);
        return;
    }
    else{
        printLossBattle(player.getName(),getName());
        while(!player.isKnockedOut()){
            player.damage(m_damage);
        }
        return;
    }
}