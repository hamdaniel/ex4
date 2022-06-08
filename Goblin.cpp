//
// Created by user on 07/06/2022.
//

#include "Goblin.h"
#include "Player.h"

Goblin::Goblin(CardName name) : Battle(name,GOBLIN_FORCE,GOBLIN_DAMAGE,GOBLIN_COINS) {};

void Goblin::applyEncounter(Player& player) {
    if (player.getAttackStrength()>=m_force) {
        player.levelUp();
        player.addCoins(m_coins);
        return;
    }
    else{
            player.damage(m_damage);
        }
        return;
    }
}
