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
     * the player lost to a vampire, so he also loses one force point
     * @param player the player whose life force is sucked out of their body
     */
    void badNews(Player& player) override;
};
#endif //EX4_VAMPIRE_H
