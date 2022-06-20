//
// Created by user on 07/06/2022.
//

#ifndef EX4_CARD_H
#define EX4_CARD_H

#include "../Players/Player.h"
#include <string>
#include "../utilities.h"
#include <iostream>
using std::cout;
using std::cin;
using std::string;


const string VAMPIRE = "Vampire";
const string GOBLIN = "Goblin";
const string DRAGON = "Dragon";
const string TREASURE = "Treasure";
const string MERCHANT = "Merchant";
const string PITFALL = "Pitfall";
const string BARFIGHT = "Barfight";
const string FAIRY = "Fairy";

class Card {
private:
    string m_cardName;
public:
    /*
    * C'tor of Card class
    *
    * @param name - The name of the card.
    * @return
    *      A new instance of Card.
   */
    Card(string& name);

    virtual ~Card() = default;

    virtual void applyEncounter(Player& Player)=0;
    string getName();
};

#endif //EX4_CARD_H
