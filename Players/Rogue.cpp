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

const string Rogue::ROGUEJOB="Rogue";

Rogue::Rogue(const char* name, int hp) : Player(name,hp){}

void Rogue::printPlayerInfo(ostream &os)
{
    printPlayerDetails(os,getName(),ROGUEJOB,getLevel(),getForce(),getHealthPoints(),getCoins());
}

void Rogue::addCoins(const int& coins)
{
    Player::addCoins(2*coins);
}


