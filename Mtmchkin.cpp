//
// Created by Daniel Hamzany on 13/06/2022.
//

#include "Mtmchkin.h"
//#include "utilities.h"
//#lnclude "Players/player.h"
//#lnclude "Players/Fighter.h"
//#lnclude "Players/Rogue.h"
//#lnclude "Players/Wizard.h"
#include <queue>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;

Mtmchkin::Mtmchkin(const std::string fileName)
{
    ifstream deck;
    deck.open(fileName);
}

int main(){
    return 0;
}