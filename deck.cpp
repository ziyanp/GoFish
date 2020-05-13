//
// Created by prasl on 4/8/2020.
//

// Ziyan Prasla (zzp64)
// 04/08/2020
//

#include "deck.h"
#include <stdlib.h>
#include <time.h>
using namespace std;


Deck::Deck()          // pristine, sorted deck
{
    myIndex = 0;


    for (int s = Card::spades; s <= Card::clubs; s++) //spades is 0 and clubs is 3
    {
        for(int i = 1; i<=13; i++)   // Goes through each suit and each rank in order
        {
            myCards[myIndex].setRank(i);

            if(s == 0)
            {
                myCards[myIndex].setSuit(Card::spades);
            }
            else if (s==1)
            {
                myCards[myIndex].setSuit(Card::hearts);

            }
            else if(s==2)
            {
                myCards[myIndex].setSuit(Card::diamonds);

            }
            else if(s==3)
            {
                myCards[myIndex].setSuit(Card::clubs);

            }
            myIndex++;

        }
    }

    myIndex = 0;

}

void Deck::shuffle()  // shuffle the deck, all 52 cards present
{
    int index = 0;


    srand(time (NULL));  // seed with current time

    while(index !=52)
    {
        int swapInd = rand() % SIZE;

        Card temp = myCards[swapInd];
        myCards[swapInd] = myCards[index];
        myCards[index] = temp;

        index++;


    }

}

Card Deck::dealCard()  // get a card, after 52 are dealt, fail
{
    Card current = myCards[myIndex];
    myIndex++;
    return current;

}

int  Deck::size() const // # cards left in the deck
{
    if(myIndex > 51)
    {
        return 0;
    } else{
        return SIZE - myIndex;

    }


}