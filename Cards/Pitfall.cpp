//
// Created by user on 08/06/2022.
//

#include "Pitfall.h"

/**
 * Pitfall card constructor
 */
Pitfall::Pitfall(string name) : Card(name) {}

void Merchant::applyEncounter(Player& player) {
Rouge* isRouge = dynamic_cast<Rouge*>(&player);
if(isRouge==NULL){
    player.buff(-10);
    printPitfallMessage(false);
    return;
}
printPitfallMessage(true);
delete isRouge;
return;
}