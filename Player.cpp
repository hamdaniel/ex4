//
// Created by user on 07/06/2022.
//

#include "Player.h"
#include "utilities.h"
#include <string>

const int MAX_LEVEL = 10;

static string getJob();

Player::Player(const char *name, int hp, int force) {
    m_name = name;
    if (force > 0) {
        m_force = force;
    } else {
        m_force = DEFAULT_FORCE;
    }
    if (hp > 0) {
        m_maxHp = hp;
    } else {
        m_maxHp = DEFAULT_HP;
    }
    m_coins = 0;
    m_level = 1;
    m_hp = m_maxHp;
}

void Player::levelUp()
{
    if(m_level<MAX_LEVEL){
        m_level++;
    }
}

int Player::getLevel() const
{
    return m_level;
}

void Player::buff(const int &forcePoints)
{
    if(forcePoints>0){
        m_force+=forcePoints;
    }
}

void Player::heal(const int &hpPoints)
{
    if(hpPoints>0){
        if(m_hp+hpPoints<=m_maxHp){
            m_hp+=hpPoints;
        }
        else{
            m_hp=m_maxHp;
        }
    }
}

void Player::damage(const int &damagePoints)
{
    if(damagePoints>0){
        if(m_hp-damagePoints>=0){
            m_hp-=damagePoints;
        }
        else{
            m_hp=0;
        }
    }
}

bool Player::isKnockedOut() const
{
    if(!m_hp){
        return true;
    }
    else{
        return false;
    }
}

void Player::addCoins(const int &coins)
{
    if(coins>0){
        m_coins+=coins;
    }
}

bool Player::pay(const int &cost)
{
    if(m_coins<cost){
        return false;
    }
    else
    {
        m_coins-=(cost>0)?cost:0;
        return true;
    }
}

int Player::getAttackStrength()
{
    return m_level+m_force;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    printPlayerDetails(os, player.m_name, player.getJob(), player.m_level, player.m_force, player.m_hp, player.m_coins);
    return os;
}

/**
 * returns the job of the player
 * @return a string that contains the player's job
 */
static string getJob()
{
    if(dynamic_cast<Rogue>(this)!= nullptr){
        return "Rogue";
    }
    if(dynamic_cast<Wizard>(this)!= nullptr){
        return "Wizard";
    }
    return "Fighter";
}