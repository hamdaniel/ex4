//
// Created by user on 07/06/2022.
//

#include "Dragon.h"
#include "../Players/player.h"
using std::string;

const string DRAGON_NAME = "Dragon";
const int DRAGON_FORCE = 25;
const int DRAGON_DAMAGE = DEFAULT_HP;
const int DRAGON_COINS = 1000;

Dragon::Dragon() : Battle(DRAGON_NAME,DRAGON_FORCE,DRAGON_DAMAGE,DRAGON_COINS) {}

