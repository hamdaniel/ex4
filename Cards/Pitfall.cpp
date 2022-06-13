//
// Created by user on 08/06/2022.
//

#include "Pitfall.h"
#include "../Players/Rogue.h"
/**
 * Pitfall card constructor
 */
Pitfall::Pitfall(string name) : Card(name) {}

void Pitfall::applyEncounter(Player& player) {
Rogue* isRogue = dynamic_cast<Rogue*>(&player);
if(isRogue==NULL){
    player.buff(-10);
    printPitfallMessage(false);
    return;
}
printPitfallMessage(true);
delete isRogue;
return;
}