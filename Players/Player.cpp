//
// Created by user on 07/06/2022.
//

#include "Player.h"
#include "utilities.h"
#include <string>
#include <iostream>
using std::cout;
using std::string;
using std::ostream;
using std::endl;

const int MAX_LEVEL = 10;

Player::Player(const char *name, int hp) {
    m_name = name;
    m_force = DEFAULT_FORCE;
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
    if(m_force+forcePoints>=0){
        m_force+=forcePoints;
    }
    else{
        m_force=0;
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

int Player::getAttackStrength() const
{
    return m_level+m_force;
}

int Player::getHealthPoints() const
{
    return m_hp;
}

int Player::getForce() const
{
    return m_force;
}

int Player::getCoins() const
{
    return m_coins;
}

const string Player::getName() const
{
    return m_name;
}

std::ostream& operator<<(std::ostream& os, const Player& player)
{
    player.printPlayerInfo(os);
    return os;
}
