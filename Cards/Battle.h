//
// Created by user on 07/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

class Battle : public Card {

private:

    /**
     * prints the battle card's info
     * @param os the stream to print the card's details to
     */
    void printCardInfo(std::ostream& os) const override;

protected:

    int m_force;
    int m_damage;
    int m_loot;

public:
    
    /**
     * Battle C'tor (battle is pure virtual)
     * @param name the name of the card
     * @param force monster's force
     * @param damage monster's damage to the player upon defeat
     * @param loot loot granted to the player upon victory
     */
    Battle(std::string name, int force, int damage, int loot);

    /**
     * Default Battle D'tor
     */
    virtual ~Battle() = default;

    /**
     * The given player faces a monster and is granted loot and levels up
     * upon victory or loses health points and deals with other effects upon defeat
     * @param player the player who faces the monster
     * @return true upon victory and false otherwise
     */
    virtual bool applyEncounter(Player& player) override;

    /**
     * the player lost against the monster and faces the consequences
     * @param player the poor player
     * @return
     *      void
     */
    virtual void badNews(Player& player);

};
#endif //EX4_BATTLE_H

