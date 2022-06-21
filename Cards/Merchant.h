//
// Created by user on 07/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H

#include "Card.h"

class Merchant : public Card {

public:

    /**
    * Merchant C'tor
    */
    Merchant();

    /**
     * Merchant D'tor
     */
    ~Merchant() = default;

    /**
    * The Player encounters the Merchant and can choose to whether to buy goods from him or not
    * @param Player the Player that encountered the Merchant
    */
    bool applyEncounter(Player& player) override;


};

#endif //EX4_MERCHANT_H
