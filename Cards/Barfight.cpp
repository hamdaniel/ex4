//
// Created by user on 08/06/2022.
//

#include "Barfight.h"
#include "Card.h"
#include "../Players/Fighter.h"
#include "../utilities.h"

using std::string;
using std::ostream;

const string BARFIGHT_NAME = "Barfight";
const int DAMAGE_TO_NON_FIGHTERS = 10;

Barfight::Barfight() : Card(BARFIGHT_NAME) {}

void Barfight::applyEncounter(Player& player) {
    if(dynamic_cast<Fighter*>(&player) == nullptr){
        player.damage(DAMAGE_TO_NON_FIGHTERS);
        printBarfightMessage(false);
        return;
    }
    printBarfightMessage(true);
    return;
}