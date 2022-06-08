//
// Created by Daniel Hamzany on 07/06/2022.
//

//#include "../utilities.h"
#include <string>
#include "Wizard.h"

Wizard::Wizard(const char* name, int hp) : Player(name,hp){}

void Wizard::heal(const int &hpPoints)
{
    if(hpPoints>0){
        if(m_hp+(2*hpPoints)<=m_maxHp){
            m_hp+=(2*hpPoints);
        }
        else{
            m_hp=m_maxHp;
        }
    }
}
string Wizard::getJob() const
{
    return "Wizard";
}
