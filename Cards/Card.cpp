//
// Created by user on 07/06/2022.
//

#include "../utilities.h"
#include "Card.h"
#include <string>

using std::string;
using std::ostream;

Card::Card(const string& name) : m_cardName(name) {}

string Card::getName() const
{
    return m_cardName;
}

void Card::printCardInfo(ostream& os) const
{
    printCardDetails(os, this->getName());
    printEndOfCardDetails(os);
}
ostream& operator<<(ostream& os, const Card& card)
{
    card.printCardInfo(os);
    return os;
}

