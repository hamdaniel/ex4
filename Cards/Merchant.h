//
// Created by user on 07/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"


class Merchant : public Card {
public:
    Merchant(string name);
    void applyEncounter(Player& player) override;
    ~Merchant()=default;
};

#endif //EX4_MERCHANT_H
