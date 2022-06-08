//
// Created by user on 07/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

const int VAMPIRE_FORCE = 10;
const int VAMPIRE_DAMAGE = 10;
const int VAMPIRE_COINS = 2;
const int VAMPIRE_DEBUFF = -1;

class Vampire : public Battle {
public:
    Vampire(string name);
    Vampire(const Vampire&) = default;
    ~Vampire() = default;
    Vampire& operator=(const Vampire& other) = default;
    void applyEncounter(Player& player) override;
};
#endif //EX4_VAMPIRE_H