//
// Created by prasl on 4/8/2020.
//

// Ziyan Prasla (zzp64)
// 04/08/2020
//

#include "card.h"
#include <string>
using namespace std;

Card::Card()
{
    mySuit = spades;
    myRank = 1; // 1 is ace

}

Card::Card(int rank, Suit s)
{
    myRank = rank;
    mySuit = s;
}

void Card::setRank(int rank)
{
    myRank = rank;
}

void Card::setSuit(Suit s)
{
    mySuit = s;
}

string Card::toString() const  // return string version e.g. Ac 4h Js
{
    string rank = rankString(myRank);
    string suit = suitString(mySuit);

    return rank + suit;





}


bool Card::sameSuitAs(const Card& c) const  // true if suit same as c
{
    return mySuit == c.mySuit;

}
int Card::getRank() const // return rank, 1..13
{
    return myRank;

}

string Card::suitString(Suit s) const  // return "s", "h",...
{
    if(s == spades)
    {
        return "s";
    }
    else if(s == hearts)
    {
        return "h";
    }
    else if(s == diamonds)
    {
        return "d";
    }
    else
    {
        return "c";
    }

}

string Card::rankString(int r) const  // return "A", "2", ..."Q"
{
    if(r == 1)
    {
        return "A";
    }
    else if (r == 11)
    {
        return "J";

    } else if (r == 12)
    {
        return "Q";
    }
    else if (r == 13)
    {
        return "K";
    }
    else
    {
        return to_string(r);
    }

}

bool Card::operator == (const Card& rhs) const   //Won't be used to compare cards in GoFish as we only want to compare ranks
{
    return myRank == rhs.myRank && mySuit == rhs.mySuit;


}
bool Card::operator != (const Card& rhs) const
{
    return myRank != rhs.myRank || mySuit != rhs.mySuit;

}


