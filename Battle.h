//
// Created by user on 07/06/2022.
//

#ifndef EX4_BATTLE_H
#define EX4_BATTLE_H

#include "Card.h"

class Battle : public Card {
    int m_force;
    int m_damage;
    int m_coins;
};
public:
    Battle(CardName name, int force, int damage, int coins);
    virtual ~Battle();
    virtual applyEncounter(Player& Player)=0;

#endif //EX4_BATTLE_H
