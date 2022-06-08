//
// Created by user on 07/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

const int DRAGON_FORCE = 25;
const int DRAGON_DAMAGE = DEFAULT_HP;
const int DRAGON_COINS = 1000;


class Dragon : public Battle {
public:
    Dragon(string name);
    Dragon(const Dragon&) = default;
    ~Dragon() = default;
    Dragon& operator=(const Dragon& other) = default;
    void applyEncounter(Player& player) override;
};

#endif //EX4_DRAGON_H
