#ifndef MTMCHKIN_H_
#define MTMCHKIN_H_


#include "utilities.h"
#include "Players/Player.h"
#include "Cards/Card.h"
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <memory>

class Mtmchkin{

public:
    
    /*
    * C'tor of Mtmchkin class
    *
    * @param filename - a file which contains the cards of the deck.
    * @return
    *      A new instance of Mtmchkin.
    */
    Mtmchkin(const std::string fileName);

    /*
    * Here we are explicitly telling the compiler that we don’t want our class to be copyable or
    * assignable at all.
   */
    Mtmchkin(const Mtmchkin&) = delete;
    Mtmchkin& operator=(const Mtmchkin& other) = delete;
    
    /*
    * Play the next Round of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void playRound();
    
    /*
    * Prints the leaderBoard of the game at a given stage of the game - according to the instruction in the exercise document.
    *
    * @return
    *      void
    */
    void printLeaderBoard() const;
    
    /*
    *  Checks if the game ended:
    *
    *  @return
    *          True if the game ended
    *          False otherwise
    */
    bool isGameOver() const;
    
	/*
    *  Returns the number of rounds played.
    *
    *  @return
    *          int - number of rounds played
    */
    int getNumberOfRounds() const;

private:
    int m_numRounds;
    std::queue<std::shared_ptr<Card>> m_deck;
    std::vector<std::unique_ptr<Player>> m_players;
};




#endif /* MTMCHKIN_H_ */
