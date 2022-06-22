//
// Created by user on 21/06/2022.
//
#include "../Mtmchkin.h"
#include "../Exception.h"

int main(){
    try{
        Mtmchkin game("deck.txt");
        while(!game.isGameOver()){
            game.playRound();
        }
        game.printLeaderBoard();
    }
    catch(const std::exception& e){
        std::cout<<e.what()<<std::endl;
    }
}