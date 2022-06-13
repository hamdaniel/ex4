//
// Created by user on 07/06/2022.
//

#ifndef EX4_PLAYER_H
#define EX4_PLAYER_H
#include <string>
#include <iostream>

const int DEFAULT_FORCE = 5;
const int DEFAULT_HP = 100;

class Player {

    /**
     * concatenates the Player according to the required format
     * @param os the stream to which the player is concatenated
     * @param player player to be concatenated
     * @return the stream with the player concatenated to it
     */
    friend std::ostream& operator<<(std::ostream& os, const Player& player);
protected:
    /**
     * C'tor of Player class-Players must have a profession, therefore no regular player should be created
     *
     * @param name - The name of the Player.
     * @param force - The starting points of force of the Player.
     * @param hp - The max hp of the Player.
     *
     */
    Player(const char* name, int hp = DEFAULT_HP);

    /**
     * Copy C'tor of Player
     */
    Player(const Player&) = default;

    /**
     * returns the current health points of the player
     * @return an int containing the health points the player currently has
     */
     int getHealthPoints() const;


    /**
     * returns the current force of the player
     * @return an int containing the force the player currently has
     */
     int getForce() const;

public:


    /**
    * Here we are explicitly telling the compiler to use the default methods
   */

    virtual ~Player() = default;
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
    virtual void heal(const int& hpPoints);

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
    * adds the given amount of coins to the player's balance
    * @param coins the amount to be added
    */
    virtual void addCoins(const int& coins);

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
    virtual int getAttackStrength() const;

    /**
     * prints the player's stats in the required format
     */
    virtual void printPlayerInfo(std::ostream &os) const=0;
    /**
     * returns the name of the player as a string
     * @return a string containing the player's name
     */
    const std::string getName() const;
    /**
     * returns the amount of coins in possession by the player
     * @return an int containing the player's balance
     */
     int getCoins() const;

private:
    std::string m_name;
    int m_level;
    int m_force;
    int m_hp;
    int m_coins;
    int m_maxHp;
};
#endif //EX2_Player_H
