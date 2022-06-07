//
// Created by Daniel Hamzany on 07/06/2022.
//

//#include "../utilities.h"
#include <string>
#include "Wizard.h"

Wizard::Wizard(const char* name, int hp) : Player(name,hp){}

string Wizard::getJob() const
{
    return "Wizard";
}
