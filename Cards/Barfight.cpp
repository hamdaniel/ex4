//
// Created by user on 08/06/2022.
//

#include "Barfight.h"

/**
 * Barfight card constructor
 */
Barfight::Barfight(string name) : Card(name) {}

void Barfight::applyEncounter(Player& player) {
    Fighter* isFighter = dynamic_cast<Fighter*>(&player);
    if(isFighter==NULL){
        player.buff(-10);
        printBarfightMessage(false);
        return;
    }
    printBarfightMessage(true);
    delete isFighter;
    return;
}