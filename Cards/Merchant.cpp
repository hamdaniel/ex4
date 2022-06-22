//
// Created by Daniel Hamzany on 07/06/2022.
//

#include "Merchant.h"
#include <string>

using std::string;
using std::cout;
using std::cin;

const string MERCHANT_NAME = "Merchant";
const int HEALTH_POTION =1;
const int HEALTH_POTION_COST = 5;
const int FORCE_BOOST =2;
const int FORCE_BOOST_COST = 10;
const int LEAVE =0;

static bool isValid(string input);

Merchant::Merchant() : Card(MERCHANT_NAME) {}

/**
 * the Player encounters the Merchant and can choose to whether to buy goods from him or not
 * @param Player the Player that encountered the Merchant
 */
bool Merchant::applyEncounter(Player& player) {
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(),player.getCoins());
    string rawInput;
    if(!std::getline(cin, rawInput)){
        throw InvalidInput();
    }
    while(!isValid(rawInput)){
        printInvalidInput();
        if(!std::getline(cin, rawInput)){
            throw InvalidInput();
        }
    }
    int input = std::stoi(rawInput);
    int paid = 0;
    if (input == LEAVE) {
        printMerchantSummary(cout, player.getName(), LEAVE, paid);
    }
    else if(input == HEALTH_POTION){
        if (player.getCoins() < HEALTH_POTION_COST) {
            printMerchantInsufficientCoins(cout);
        }
        else{
            player.pay(HEALTH_POTION_COST);
            paid = HEALTH_POTION_COST;
            player.heal(1);
        }
        printMerchantSummary(cout,player.getName(),HEALTH_POTION, paid);
    }
    else{
        if (player.getCoins() < FORCE_BOOST_COST) {
            printMerchantInsufficientCoins(cout);
        }
        else{
            player.pay(FORCE_BOOST_COST);
            paid = FORCE_BOOST_COST;
            player.buff(1);
        }
        printMerchantSummary(cout,player.getName(),FORCE_BOOST, paid);
    }
    return false;
}

static bool isValid(string input) {
    if (input.size() != 1) {
        return false;
    }
    if (!std::isdigit(input[0])) {
        return false;
    }
    if (std::stoi(input)!=LEAVE && std::stoi(input)!=HEALTH_POTION && std::stoi(input)!=FORCE_BOOST){
        return false;
    }
    return true;
}