//
// Created by user on 08/06/2022.
//

#include "Treasure.h"

using std::string;

const string TREASURE_NAME = "Treasure";

Treasure::Treasure() : Card(TREASURE_NAME) {}

bool Treasure::applyEncounter(Player& player) {
    player.addCoins(10);
    printTreasureMessage();
    return false;
}