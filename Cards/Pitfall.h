//
// Created by user on 08/06/2022.
//

#ifndef EX4_PITFALL_H
#define EX4_PITFALL_H

#include "Card.h"

class Pitfall : public Card {

public:

    /**
     * C'tor of pitfall
     */
    Pitfall();

    /**
     * Default pitfall D'tor
     */
    ~Pitfall()=default;

    /**
     * The player falls in a pitfall and is damaged unless he is a rogue
     * @param player the player that fell to the trap
     */
    bool applyEncounter(Player& player) override;

};

#endif //EX4_PITFALL_H
