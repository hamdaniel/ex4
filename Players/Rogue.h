//
// Created by Daniel Hamzany on 07/06/2022.
//

#ifndef EX4_ROGUE_H
#define EX4_ROGUE_H
#include "Player.h"
#include <string>
#include <iostream>

class Rogue : public Player{

    /**
     * concatenates the rogue according to the required format
     * @param os the stream to which the rogue is concatenated
     * @param rogue Rogue to be concatenated
     * @return the stream with the rogue concatenated to it
     */
    friend std::ostream& operator<<(std::ostream& os, const Rogue& rogue);
private:
    static const std::string ROGUEJOB;
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
     * prints the player's stats in the required format
     */
    void printPlayerInfo(std::ostream &os) const override;

    /**
     * adds the given amount of coins to the player's balance
     * @param coins the amount to be added
     */
    void addCoins(const int& coins) override;

};
#endif //EX4_ROGUE_H
