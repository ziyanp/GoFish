//
// Created by prasl on 4/8/2020.
// Ziyan Prasla (zzp64)
// 04/08/2020
//
#include "player.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
using namespace std;

Player::Player()
{
    myName = "John Doe";
}




void Player::addCard(Card c) //adds a card to the hand
{
    myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2) //adds the pair to books
{
    myBook.push_back(c1);
    myBook.push_back(c2);
}

//OPTIONAL
// comment out if you decide to not use it
//this function will check a players hand for a pair.
//If a pair is found, it returns true and populates the two variables with the cards tha make the pair.

bool Player::checkHandForBook(Card &c1, Card &c2) //error
{

    for(int i=0; i<myHand.size()-1; i++)
    {
        int currentRank = myHand[i].getRank();

        for(int j=i+1; j<myHand.size(); j++)
        {
            int secondRank = myHand[j].getRank();


            if(currentRank == secondRank)
            {
                c1 = myHand[i];
                c2 = myHand[j];
                return true;
            }
        }
    }

    return false;
}



//uses some strategy to choose one card from hand
Card Player::chooseCardFromHand() const
{

    srand(time (NULL));  // seed with current time

    int cardInd = rand() % myHand.size(); //random card from hand

    return myHand[cardInd];


}

//Does the player have the card c in her hand? (only checking for rank)
bool Player::cardInHand(Card c) const
{
    for(int i = 0; i<myHand.size(); i++)
    {
        if(myHand[i].getRank() == c.getRank())
        {
            return true;
        }

    }

    return false;
}

//Remove the card c from the hand and return it to the caller (card of same rank)
Card Player::removeCardFromHand(Card c)
{
    for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); it++)
    {
        if((*it).getRank() == c.getRank())
        {
            Card removedCard = *it;
            myHand.erase(it, it+1);
            return removedCard;
        }
    }

}

string Player::showHand() const
{
    string hand;

    for(int i = 0; i<myHand.size(); i++)
    {
        hand += myHand[i].toString() + " "; //prints all cards
    }

    return hand;
}

string Player::showBooks() const
{
    string books;
    for(int i = 0; i<myBook.size(); i+=2)
    {

        books += myBook[i].toString() + "&" + myBook[i+1].toString() + " , ";
    }

    return books;
}

int Player::getHandSize() const
{
    return myHand.size();

}

int Player::getBookSize() const
{
    return myBook.size()/2;
}





