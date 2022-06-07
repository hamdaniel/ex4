//
// Created by user on 07/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "Player.h"

/*
 *  CardName:
 *  Each card has a name:
 *  Vampire
 *  Goblin
 *  Dragon
 *  Treasure
 *  Merchant
 *  Pitfall
 *  Barfight
 *  Fairy
*/
enum class CardName {Vampire, Goblin, Dragon, Treasure, Merchant, Pitfall, Barfight ,Fairy}; // The type of the Card

class Card {
private:
    CardName m_name;
public:
    /*
    * C'tor of Card class
    *
    * @param name - The name of the card.
    * @return
    *      A new instance of Card.
   */
    Card(CardName name);

    virtual ~Card();

    virtual applyEncounter(Player& Player)=0;
}

#endif //EX4_CARD_H
