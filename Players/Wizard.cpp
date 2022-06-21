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

const string WIZARDJOB="Wizard";

Wizard::Wizard(const string name) : Player(name){}

void Wizard::heal(const int &hpPoints)
{
    Player::heal(2*hpPoints);
}

void Wizard::printPlayerInfo(ostream &os) const
{
    printPlayerDetails(os,getName(),WIZARDJOB,getLevel(),getForce(),getHealthPoints(),getCoins());
}

std::ostream& operator<<(std::ostream& os, const Wizard& wizard)
{
    wizard.printPlayerInfo(os);
    return os;
}
