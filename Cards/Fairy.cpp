//
// Created by user on 09/06/2022.
//

#include "Fairy.h"

/**
 * Fairy card constructor
 */
Fairy::Fairy(string name) : Card(name) {}

void Fairy::applyEncounter(Player& player) {
    Wizard* isWizard = dynamic_cast<Wizard*>(&player);
    if(isWizard==NULL){
        printFairyMessage(false);
        return;
    }
    player.buff(10); //should increment by 20
    printFairyMessage(true);
    delete isWizard;
    return;
}