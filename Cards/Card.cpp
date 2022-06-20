//
// Created by user on 07/06/2022.
//

#include "Card.h"

Card::Card(string& name) : m_cardName(name) {}

string Card::getName()
{
    return m_cardName;
}

