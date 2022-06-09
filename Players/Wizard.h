//
// Created by Daniel Hamzany on 07/06/2022.
//

#ifndef EX4_WIZARD_H
#define EX4_WIZARD_H
#include "Player.h"
#include <string>
using std::string;

class Wizard : public Player{

private:
    static const string rougeJob = "Rogue";
public:
    /**
     * C'tor of Wizard class
     *
     * @param name - The name of the Wizard.
     * @param force - The starting points of force of the Wizard.
     * @param hp - The max hp of the Wizard.
     *
     */
    Wizard(const char* name, int hp = DEFAULT_HP);

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
     *
     * @return
     */
    string getJob() const override;
};
#endif //EX4_WIZARD_H
