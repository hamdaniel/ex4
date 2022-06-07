//
// Created by user on 07/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {
public:
    Merchant();
    bool applyEncounter(Player& Player);
};

#endif //EX4_MERCHANT_H
