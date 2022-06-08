//
// Created by user on 07/06/2022.
//

#ifndef EX4_GOBLIN_H
#define EX4_GOBLIN_H
#include "Battle.h"

const int GOBLIN_FORCE = 6;
const int GOBLIN_DAMAGE = 10;
const int GOBLIN_COINS = 2;

class Goblin : public Battle {
public:
    Goblin(CardName name);
    Goblin(const Goblin&) = default;
    ~Goblin() = default;
    Goblin& operator=(const Goblin& other) = default;
    void applyEncounter(Player& player) override;
};

#endif //EX4_GOBLIN_H
