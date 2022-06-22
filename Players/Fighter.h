//
// Created by Daniel Hamzany on 07/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H

#include <string>
#include <iostream>
#include "Player.h"

class Fighter : public Player {

public:

    /**
     * C'tor of Fighter class
     * @param name - The name of the Fighter.
     */
    Fighter(const std::string name);

    /**
    * attack strength for Fighter is calculated differently, calculates as specified in instructions
     * @return attack strength(force times two plus level)
   */
   int getAttackStrength() const override;


    /**
     * Here we are explicitly telling the compiler to use the default methods
     */
    Fighter(const Fighter&) = default;
    ~Fighter() = default;
    Fighter& operator=(const Fighter& other) = default;

    /**
     * prints the player's stats in the required format
     */
    void printPlayerInfo(std::ostream &os) const override;

};
#endif //EX4_FIGHTER_H
