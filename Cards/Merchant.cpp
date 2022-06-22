//
// Created by Daniel Hamzany on 07/06/2022.
//

#include "Merchant.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

const string MERCHANT_NAME = "Merchant";
const string HEALTH_POTION = "1";
const int HEALTH_POTION_COST = 5;
const string FORCE_BOOST = "2";
const int FORCE_BOOST_COST = 10;
const string LEAVE = "0";

static bool isValid(string input);

Merchant::Merchant() : Card(MERCHANT_NAME) {}

/**
 * the Player encounters the Merchant and can choose to whether to buy goods from him or not
 * @param Player the Player that encountered the Merchant
 */
bool Merchant::applyEncounter(Player& player)
{
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(),player.getCoins());
    string input;
    if(!std::getline(cin, input)){
        throw InvalidInput();
    }
    while(!isValid(input)){
        printInvalidInput();
        if(!std::getline(cin, input)){
            throw InvalidInput();
        }
    }
    string action = LEAVE;
    int paid = 0;
    if(!input.compare(HEALTH_POTION)){
        action = HEALTH_POTION;
        if (player.getCoins() >= HEALTH_POTION_COST){
            player.pay(HEALTH_POTION_COST);
            paid = HEALTH_POTION_COST;
            player.heal(1);
        }
    }
    if(!input.compare(FORCE_BOOST)){
        action = FORCE_BOOST;
        if (player.getCoins() >= FORCE_BOOST_COST){
            player.pay(FORCE_BOOST_COST);
            paid = FORCE_BOOST_COST;
            player.buff(1);
        }
    }
    if(action.compare(LEAVE) &&  paid == 0){
        printMerchantInsufficientCoins(cout);
    }
    printMerchantSummary(cout, player.getName(), std::stoi(action), paid);
    return false;
}

static bool isValid(string input)
{
    if (!input.compare(LEAVE) && !input.compare(HEALTH_POTION) && !input.compare(FORCE_BOOST)){
        return false;
    }
    return true;
}