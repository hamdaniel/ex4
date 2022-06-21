//
// Created by user on 07/06/2022.
//

#ifndef EX4_VAMPIRE_H
#define EX4_VAMPIRE_H

#include "Battle.h"

class Vampire : public Battle {

public:

    /**
     * Vampire C'tor
     */
    Vampire();

    /**
     * Default Vampire D'tor
     */
    ~Vampire() = default;

    /**
     * The player faces an evil vampire, and is granted coins and levels up upon victory and loses health points
     * and one force point upon defeat
     * @param player the player who faces the vampire
     */
    void applyEncounter(Player& player) override;
};
#endif //EX4_VAMPIRE_H
