//
// Created by Daniel Hamzany on 07/06/2022.
//

#include "Merchant.h"
#include <iostream>
using std::cout;

/**
 * Merchant card constructor
 */
Merchant(string name) : Card(name){}

/**
 * the Player encounters the Merchant and can choose to whether to buy goods from him or not
 * @param Player the Player that encountered the Merchant
 */
void applyEncounter(Player& Player)
{
    player.encounterMerchant();
}
