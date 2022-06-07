//
// Created by user on 07/06/2022.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H

#include <string>
#include "utilities.h"


const int DEFAULT_FORCE = 5;
const int DEFAULT_HP = 100;



class Player {
    /**
     * concatenation operator for Player
     * @return ostream with the Player data
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player)
public:
    /**
     * C'tor of Player class
     *
     * @param name - The name of the player.
     * @param force - The starting points of force of the player.
     * @param hp - The max hp of the player.
     *
     */
    Player(const char* name, int hp = DEFAULT_HP);

    /**
    * Here we are explicitly telling the compiler to use the default methods
   */
    Player(const Player&) = default;
    ~Player() = default;
    Player& operator=(const Player& other) = default;

    /**
     * increases the player's level by 1.
     * if the level is already maxed out (level 10) - does nothing.
     *
     * @return
     *      void
     */
    void levelUp();

    /**
     * return the player's current level.
     *
     * @return
     *      int
     */
    int getLevel() const;

    /**
     * increases the player's force by the amount received as an argument.
     * @param forcePoints - the amount of force points to be added.
     *
     * @return
     *      void
     */
    void buff(const int& forcePoints);

    /**
    * increases the player's hp by the amount received as an argument.
    * if hp is already maxed out - does nothing.
    * @param hpPoints - the amount of hp points to be added.
    *
    * @return
    *      void
    */
    void heal(const int& hpPoints);

    /**
    * lowers the player's hp by the amount received as an argument.
    * @param damagePoints - the amount of hp points to be removed.
    *
    * @return
    *      void
    */
    void damage(const int& damagePoints);

    /**
    * checks if hp has reached 0.
    * prints "Player is knocked out" if hp is 0.
     *
    * @return
    *      true - if hp=0.
    *      false - else.
    */
    bool isKnockedOut() const;

    /**
    * increases the player's coins by the amount received as an argument.
    *
    * @param coins - the amount of coins to be added.
    *
    * @return
    *      void
    */
    void addCoins(const int& coins);

    /**
    * removes the amount received as an argument from the player's coins - if the player has enough coins.
    *
    * @param cost - the amount of coins to be removed.
    * @return
    *      true - when coins were successfully removed.
    *      false - when the player does not have enough coins (less than the amount received as an argument)
    */
    bool pay(const int& cost);

    /**
    * return the attack force (level+force).
    *
    * @return
    *      int
    */
    int getAttackStrength();

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
    int m_maxHp;
};
#endif //EX2_Player_H
