//
// Created by Daniel Hamzany on 21/06/2022.
//

#ifndef EX4_GANG_H
#define EX4_GANG_H

#include "Card.h"
#include "Battle.h"
#include "Dragon.h"
#include "Vampire.h"
#include "Goblin.h"
#include <vector>
#include <string>
#include <memory>

class Gang : public Card {

private:

    std::vector<std::unique_ptr<Battle>> m_monsters;

public:

    /**
     * Gang C'tor
     * @param monsters the monsters in the gang
     */
    Gang(const std::vector<std::string>& monsters);

    /**
     * Gang copy C'tor
     */
    Gang(const Gang& other);

    /**
     * Gang assignment operator
     * @param other gang to be assigned
     * @return a reference to the assigned gang;
     */
    Gang& operator=(const Gang& other);

    /**
     * The player faces a gang of monsters one by one and will receive loot for every defeated monster,
     * and one level for defeating the whole gang. upon defeat the player will be damaged by every monster left
     * @param player the poor player who faces the gang
     * @return true upon victory and false otherwise
     */
    bool applyEncounter(Player& player) override;


};


#endif //EX4_GANG_H
