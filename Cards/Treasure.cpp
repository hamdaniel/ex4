//
// Created by user on 08/06/2022.
//

#include "Treasure.h"

/**
 * Treasure card constructor
 */
Treasure::Treasure(string name) : Card(name) {}

void Treasure::applyEncounter(Player& player) {
    player.addCoins(10);
    printTreasureMessage();
}