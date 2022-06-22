//
// Created by user on 07/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "../Players/Player.h"
#include "../utilities.h"
#include <string>

class Card {

private:

    std::string m_cardName;

protected:
    /**
     * print card details to the given stream
     * @param os stream the card is printed to
     */
    virtual void printCardInfo(std::ostream& os) const;

public:

    /**
     * returns the card's name
     * @return string containing the card's name
     */
    std::string getName() const;

    /**
    * Card C'tor(Card is pure virtual)
    * @param name - The name of the card.
    *
    */
    Card(const std::string& name);

    /**
     * Default Card D'tor
     */
    virtual ~Card() = default;

    /**
     * The player whose turn it is draws a card from the deck and faces its contents
     * @param Player the player which draws the card
     * @return
     *  true - if the player won against a battle card
     *  false - else
     */
    virtual bool applyEncounter(Player& Player)=0;

    /**
     * concatenates the Card according to the required format
     * @param os the stream to which the card is concatenated
     * @param card card to be concatenated
     * @return the stream with the card concatenated to it
     */
    friend std::ostream& operator<<(std::ostream& os, const Card& card);
};



#endif //EX4_CARD_H
