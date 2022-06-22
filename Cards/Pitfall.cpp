//
// Created by user on 08/06/2022.
//

#include "Pitfall.h"
#include "../Players/Rogue.h"

using std::string;

const string PITFALL_NAME = "Pitfall";

Pitfall::Pitfall() : Card(PITFALL_NAME) {}

bool Pitfall::applyEncounter(Player& player)
{
    if(dynamic_cast<Rogue*>(&player)== nullptr){
        player.damage(10);
        printPitfallMessage(false);
        return false;
    }
    printPitfallMessage(true);
    return false;
}