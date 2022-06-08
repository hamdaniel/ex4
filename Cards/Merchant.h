//
// Created by user on 07/06/2022.
//

#ifndef EX4_MERCHANT_H
#define EX4_MERCHANT_H
#include "utilities.h"
#include "//Players/Player.h"
#include "Card.h"
#include <string>
using std::string;

class Merchant : public Card {
public:
    Merchant(string name);
    void applyEncounter(Player& Player) override;
    ~Merchant()=default;
};

#endif //EX4_MERCHANT_H
