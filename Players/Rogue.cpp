//
// Created by Daniel Hamzany on 07/06/2022.
//
//#include "../utilities.h"
#include <string>
#include "Rogue.h"

Rogue::Rogue(const char* name, int hp) : Player(name,hp){}

string Rogue::getJob() const
{
    return "Rogue";
}



