//
// Created by Daniel Hamzany on 07/06/2022.
//

#include "Wizard.h"
#include <string>
#include "../utilities.h"


using std::cout;
using std::string;
using std::ostream;
using std::endl;

const string Wizard::WIZARDJOB="Wizard";

Wizard::Wizard(const char* name, int hp) : Player(name,hp){}

void Wizard::heal(const int &hpPoints)
{
    Player::heal(2*hpPoints);
}

void Wizard::printPlayerInfo(ostream &os)
{
    printPlayerDetails(os,getName(),WIZARDJOB,getLevel(),getForce(),getHealthPoints(),getCoins());
}
