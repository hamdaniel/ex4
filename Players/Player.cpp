//
// Created by user on 07/06/2022.
//

#include "Player.h"
//#include "../utilities.h"
#include <string>
#include <iostream>
using std::cout;
using std::string;
using std::ostream;
using std::endl;

const int MAX_LEVEL = 10;

//static void printPlayerDetails(ostream &os, const std::string &name, const std::string &job, int level, int force, int HP, int coins);

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

int Player::getLevel()
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

bool Player::isKnockedOut()
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

int Player::getHealthPoints()
{
    return m_hp;
}

int Player::getForce()
{
    return m_force;
}

//static void printPlayerDetails(ostream &os, const std::string &name, const std::string &job, int level, int force, int HP, int coins)
//{
//    const int nameDistance = 16;
//    const int distance = 6;
//    os << name;
//    for(unsigned int i = 0; i < nameDistance - name.size(); i++){
//        os << " ";
//    }
//    os << level;
//    if(level < 10){
//        os << " ";
//    }
//    os <<  "        " << force;
//    for(unsigned int i = 0; i < distance - std::to_string(force).size(); i++){
//        os << " ";
//    }
//    os << HP;
//    for(unsigned int i = 0; i < distance - std::to_string(HP).size(); i++){
//        os << " ";
//    }
//    os << coins;
//    for(unsigned int i = 0; i < distance - std::to_string(coins).size(); i++){
//        os << " ";
//    }
//    os << job << "  ";
//}

int Player::getCoins()
{
    return m_coins;
}

const string Player::getName()
{
    return m_name;
}