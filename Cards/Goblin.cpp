//
// Created by user on 07/06/2022.
//

#include "Goblin.h"

Goblin::Goblin(string name) : Battle(name,GOBLIN_FORCE,GOBLIN_DAMAGE,GOBLIN_COINS) {}

void Goblin::applyEncounter(Player& player) {
    if (player.getAttackStrength() >= m_force) {
        printWinBattle(player.getName(),getName());
        player.levelUp();
        player.addCoins(m_coins);
        return;
    } else {
        printLossBattle(player.getName(),getName());
        player.damage(m_damage);
        return;
    }
}
