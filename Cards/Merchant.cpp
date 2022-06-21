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
const int FORCE_BOOST =2;
const int LEAVE =0;

Merchant::Merchant() : Card(MERCHANT_NAME) {}

/**
 * the Player encounters the Merchant and can choose to whether to buy goods from him or not
 * @param Player the Player that encountered the Merchant
 */
void Merchant::applyEncounter(Player& player) {
    printMerchantInitialMessageForInteractiveEncounter(cout, player.getName(),player.getCoins());
    int input;
    cin >> input;
    while (input!=HEALTH_POTION&&input!=FORCE_BOOST&&input!=LEAVE){
        printInvalidInput();
        cin >> input;
    }
    if(input==HEALTH_POTION){
        if(player.getCoins()<5){
            printMerchantInsufficientCoins(cout);
        }
        else {
            player.pay(5);
            player.heal(1);
            printMerchantSummary(cout, player.getName(),HEALTH_POTION,5);
        }
    }
    else if(input==FORCE_BOOST){
        if(player.getCoins()<10){
            printMerchantInsufficientCoins(cout);
        }
        else{
            player.pay(10);
            player.buff(1);
            printMerchantSummary(cout,player.getName(),FORCE_BOOST,10);
        }
    }
    else{
        printMerchantSummary(cout,player.getName(),LEAVE,0);
    }
}