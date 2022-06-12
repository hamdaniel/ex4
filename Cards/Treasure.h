//
// Created by user on 08/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card {
public:
    Treasure(string name);
    void applyEncounter(Player& player) override;
    ~Treasure()=default;
};

#endif //EX4_TREASURE_H
