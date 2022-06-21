//
// Created by Daniel Hamzany on 07/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"
#include <string>
#include <iostream>

class Wizard : public Player{

    /**
     * concatenates the wizard according to the required format
     * @param os the stream to which the wizard is concatenated
     * @param wizard wizard to be concatenated
     * @return the stream with the wizard concatenated to it
     */
    friend std::ostream& operator<<(std::ostream& os, const Wizard& wizard);
private:
public:
    /**
     * C'tor of Wizard class
     *
     * @param name - The name of the Wizard.
     *
     */
    Wizard(const std::string name);

    /**
    * Here we are explicitly telling the compiler to use the default methods
   */
    Wizard(const Wizard&) = default;
    ~Wizard() = default;
    Wizard& operator=(const Wizard& other) = default;

    /**
     * heals the Wizard for twice the given amount
     * @param hpPoints hp to heal (twice)
     */
    void heal(const int& hpPoints) override;

    /**
     * prints the player's stats in the required format
    */
    void printPlayerInfo(std::ostream &os) const override;
};
#endif //EX4_WIZARD_H
