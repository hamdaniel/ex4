//
// Created by user on 08/06/2022.
//

#ifndef EX4_TREASURE_H
#define EX4_TREASURE_H

#include "Card.h"

class Treasure : public Card {

public:

    /**
     * Treasure C'tor
     */
    Treasure();

    /**
     * Default Treasure D'tor
     */
    ~Treasure()=default;

    /**
     * The player found a treasure chest and is heavily rewarded
     * @param player the player which adds 10 coins to his balance
     */
    void applyEncounter(Player& player) override;


};

#endif //EX4_TREASURE_H
