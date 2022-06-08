//
// Created by Daniel Hamzany on 07/06/2022.
//

#ifndef EX4_FIGHTER_H
#define EX4_FIGHTER_H
#include "Player.h"
#include <string>
#include <iostream>
using std::cout;
using std::string;
using std::ostream;
using std::endl;

class Fighter : public Player {

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
   int getAttackStrength() override;


    /**
     * Here we are explicitly telling the compiler to use the default methods
     */
    Fighter(const Fighter&) = default;
    ~Fighter() = default;
    Fighter& operator=(const Fighter& other) = default;

    /**
     *
     * @return
     */
    string getJob() const override;

};
#endif //EX4_FIGHTER_H
