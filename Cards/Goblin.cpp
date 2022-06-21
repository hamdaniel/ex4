//
// Created by user on 07/06/2022.
//

#include "Goblin.h"

using std::string;
const string GOBLIN_NAME = "Goblin";

Goblin::Goblin() : Battle(GOBLIN_NAME,GOBLIN_FORCE,GOBLIN_DAMAGE,GOBLIN_COINS) {}

void Goblin::applyEncounter(Player& player) {
    if (player.getAttackStrength() >= m_force) {
        printWinBattle(player.getName(),getName());
        player.levelUp();
        player.addCoins(m_loot);
        return;
    } else {
        printLossBattle(player.getName(),getName());
        player.damage(m_damage);
        return;
    }
}
