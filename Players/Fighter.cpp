//
// Created by Daniel Hamzany on 07/06/2022.
//

#include "Fighter.h"
#include <string>
#include "../utilities.h"

using std::cout;
using std::string;
using std::ostream;
using std::endl;

const string Fighter::FIGHTERJOB="Fighter";

Fighter::Fighter(const string name) : Player(name){}

int Fighter::getAttackStrength() const
{
    return getForce()*2+getLevel();
}

void Fighter::printPlayerInfo(ostream &os)  const
{
    printPlayerDetails(os,getName(),FIGHTERJOB,getLevel(),getForce(),getHealthPoints(),getCoins());
}

std::ostream& operator<<(std::ostream& os, const Fighter& fighter)
{
    fighter.printPlayerInfo(os);
    return os;
}