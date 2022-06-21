//
// Created by user on 09/06/2022.
//

#include "Fairy.h"
#include "../Players/Wizard.h"

using std::string;

const string FAIRY_NAME = "Fairy";

Fairy::Fairy() : Card(FAIRY_NAME) {}

bool Fairy::applyEncounter(Player& player) {
    if(dynamic_cast<Wizard*>(&player)== nullptr){
        printFairyMessage(false);
        return false;
    }
    player.heal(10);
    printFairyMessage(true);
    return false;
}