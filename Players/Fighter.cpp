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

Fighter::Fighter(const char* name, int hp) : Player(name,hp){}

int Fighter::getAttackStrength()
{
    return Player::getAttackStrength()*2-getLevel();
}

void Fighter::printPlayerInfo(ostream &os)
{
    printPlayerDetails(os,getName(),FIGHTERJOB,getLevel(),getForce(),getHealthPoints(),getCoins());
}

//int main(){
//    return 0;
//}