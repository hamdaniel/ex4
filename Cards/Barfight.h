//
// Created by user on 08/06/2022.
//

#ifndef EX4_BARFIGHT_H
#define EX4_BARFIGHT_H

#include "Card.h"

class Barfight : public Card {

public:

     /**
     *
     * Barfight C'tor
     */
    Barfight();

     /**
     * Default Barfight D'tor
     */
    ~Barfight() = default;

    /**
    * The player participates in a barfight and loses 10 health points if he is not a fighter
    * @param player the player that participates in the barfight
    */
    bool applyEncounter(Player& player) override;

};


#endif //EX4_BARFIGHT_H
