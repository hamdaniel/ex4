//
// Created by user on 08/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"
class Barfight : public Card {
public:
    Barfight(string name);
    void applyEncounter(Player& player) override;
    ~Barfight() override=default;
};


#endif //EX4_BARFIGHT_H
