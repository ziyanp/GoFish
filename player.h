
// Ziyan Prasla (zzp64)
// 04/08/2020
//

#ifndef _PLAYER_H
#define _PLAYER_H

#include <iostream>
#include <string>
#include <vector>


#include "card.h"
using namespace std;


class Player
{
  public:
    Player();

    Player(string name) {
       myName = name;
    }

    string getName() const {
       return myName;
    }
    
    void addCard(Card c);  //adds a card to the hand
    void bookCards(Card c1, Card c2);

    //OPTIONAL
    // comment out if you decide to not use it
    //this function will check a players hand for a pair. 
    //If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

    bool checkHandForBook(Card &c1, Card &c2);


    
    //uses some strategy to choose one card from the player's
    //hand so they can say "Do you have a 4?"
    Card chooseCardFromHand() const; 
    
    //Does the player have the card c in her hand?
    bool cardInHand(Card c) const; 
    
    //Remove the card c from the hand and return it to the caller
    Card removeCardFromHand(Card c); 
    
    string showHand() const; 
    string showBooks() const; 
    
    int getHandSize() const; 
    int getBookSize() const; 
       


    
    
  private:
          
    vector <Card> myHand;
    vector <Card> myBook;
    
    string myName;     
   
};


#endif
