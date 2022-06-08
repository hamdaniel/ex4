//
// Created by user on 08/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"
class Fairy : public Card {
public:
    Fairy(string name);
    void applyEncounter(Player& player) override;
    ~Fairy()=default;
};

#endif //EX4_FAIRY_H
