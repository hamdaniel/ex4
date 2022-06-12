//
// Created by user on 08/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card {
public:
    Pitfall(string name);
    void applyEncounter(Player& player) override;
    ~Pitfall()=default;
};

#endif //EX4_PITFALL_H
