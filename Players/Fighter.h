//
// Created by Daniel Hamzany on 07/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"
#include "utilities.h"
#include <string>
#include <iostream>

class Fighter : public Player {

    /**
     * concatenates the fighter according to the required format
     * @param os the stream to which the fighter is concatenated
     * @param fighter fighter to be concatenated
     * @return the stream with the fighter concatenated to it
     */
    friend std::ostream& operator<<(std::ostream& os, const Fighter& fighter);

private:
    static const std::string FIGHTERJOB;

public:
    /**
     * C'tor of Fighter class
     *
     * @param name - The name of the Fighter.
     * @param force - The starting points of force of the Fighter.
     * @param hp - The max hp of the Fighter.
     *
     */
    Fighter(const char* name, int hp = DEFAULT_HP);

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
