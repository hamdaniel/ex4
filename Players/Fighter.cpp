//
// Created by Daniel Hamzany on 07/06/2022.
//
//#include "../utilities.h"
#include <string>
#include "Fighter.h"

Fighter::Fighter(const char* name, int hp) : Player(name,hp){}

int Fighter::getAttackStrength()
{
    return m_level+2*m_force;
}

string Fighter::getJob () const
{
    return "Fighter";
}


int main(){
    cout<<"hellooooo"<<endl;
    return 0;
}