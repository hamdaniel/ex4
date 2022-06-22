//
// Created by user on 08/06/2022.
//

#ifndef EX4_FAIRY_H
#define EX4_FAIRY_H

#include "Card.h"

class Fairy : public Card {

public:

    /**
     * Fairy C'tor
     */
    Fairy();

    /**
     * Default Fairy D'tor
     */
    ~Fairy() = default;

    /**
     * The player faces a fairy, which will heal him if he is a wizard
     * @param player the player who faces the fairy
     * @return
     *  false - always
     */
    bool applyEncounter(Player& player) override;


};

#endif //EX4_FAIRY_H
