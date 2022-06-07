//
// Created by Daniel Hamzany on 07/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"
#include <string>
using std::string;

class Rogue : public Player{

public:
    /**
     * C'tor of Rogue class
     *
     * @param name - The name of the Rogue.
     * @param force - The starting points of force of the Rogue.
     * @param hp - The max hp of the Rogue.
     *
     */
    Rogue(const char* name, int hp = DEFAULT_HP);

    /**
    * Here we are explicitly telling the compiler to use the default methods
   */
    Rogue(const Rogue&) = default;
    ~Rogue() = default;
    Rogue& operator=(const Rogue& other) = default;

    /**
     *
     * @return
     */
    string getJob() const override;
};
#endif //EX4_ROGUE_H
