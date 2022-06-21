//
// Created by user on 07/06/2022.
//

#ifndef EX4_DRAGON_H
#define EX4_DRAGON_H

#include "Battle.h"

class Dragon : public Battle {

public:

    /**
     * Dragon C'tor
     */
    Dragon();

    /**
     * Default Dragon D'tor
     */
    ~Dragon() = default;

    /**
     * The player faces a mighty dragon and receives much loot and levels up
     * upon victory but loses all health upon defeat
     * @param player the player who faces the dragon
     */
    void applyEncounter(Player& player) override;


};

#endif //EX4_DRAGON_H
