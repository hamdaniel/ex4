//
// Created by user on 07/06/2022.
//
#include "Vampire.h"

using std::string;

const string VAMPIRE_NAME = "Vampire";
const int VAMPIRE_FORCE = 10;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_COINS = 2;
const int VAMPIRE_DEBUFF = -1;

Vampire::Vampire()  : Battle(VAMPIRE_NAME,VAMPIRE_FORCE,VAMPIRE_DAMAGE,VAMPIRE_COINS) {}

void Vampire::badNews(Player &player)
{
    Battle::badNews(player);
    player.buff(VAMPIRE_DEBUFF);
}


