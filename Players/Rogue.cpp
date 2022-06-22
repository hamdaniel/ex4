//
// Created by Daniel Hamzany on 07/06/2022.
//
#include "Rogue.h"
#include <string>
#include "../utilities.h"


using std::cout;
using std::string;
using std::ostream;
using std::endl;

const string ROGUEJOB = "Rogue";

Rogue::Rogue(const string name) : Player(name){}

void Rogue::addCoins(const int& coins)
{
    Player::addCoins(2 * coins);
}

void Rogue::printPlayerInfo(ostream &os) const
{
    printPlayerDetails(os, getName(), ROGUEJOB, getLevel(), getForce(), getHealthPoints(), getCoins());
}