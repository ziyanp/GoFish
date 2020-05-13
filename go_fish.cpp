
// This is a demonstration for GoFish
// Ziyan Prasla (zzp64)
// 04/08/2020
// GoFish Game Driver
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <fstream>

using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);




int main( )
{

    int numCards = 7;  //7 cards for 2 player game
    
    Player p1("Ziyan");
    Player p2("Warren");
    
    Deck d;  //create a deck of cards
    d.shuffle();
    
    dealHand(d, p1, numCards);
    dealHand(d, p2, numCards);
       
    cout << "Check gofish_results.txt file to see results"<<endl;

    ofstream myfile ("gofish_results.txt");

    if(myfile.is_open())
    {
        myfile << p1.getName() <<" has : " << p1.showHand()<<endl;   // original hands
        myfile << p2.getName() <<" has : " << p2.showHand()<<endl;
        myfile<<endl;

        myfile << "GAME BEGINS" <<endl;

        myfile<<endl;

        Card c1;
        Card c2;

        //check for books in starting hand of player 1
        while(p1.checkHandForBook(c1, c2))  //places booked cards in c1 and c2
        {
            p1.removeCardFromHand(c1);
            p1.removeCardFromHand(c2);

            p1.bookCards(c1, c2);

            myfile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
            myfile << endl;
            myfile << endl;
        }

        //checks books in starting hand of player 2
        while(p2.checkHandForBook(c1, c2))  //places booked cards in c1 and c2
        {

            p2.removeCardFromHand(c1);
            p2.removeCardFromHand(c2);
            p2.bookCards(c1, c2);

            myfile << p2.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
            myfile << endl;
            myfile << endl;
        }

        myfile << p1.getName() <<" now has : " << p1.showHand()<<endl;
        myfile << p2.getName() <<" now has : " << p2.showHand()<<endl;
        myfile << endl;
        myfile << endl;

        while(d.size() > 0 || p1.getHandSize() > 0 || p2.getHandSize() > 0) // only play if there are cards remaining in the deck or in the players hands
        {
            // PLAYER 1 TURN

            if(p1.getHandSize() <= 0)    //if hand is empty draw another and switch turns
            {
                c1 = d.dealCard();
                p1.addCard(c1);
                myfile << p1.getName() << " draws a " << c1.toString()<<endl;
                myfile<<endl;
            }
            else {
                c1 = p1.chooseCardFromHand();
               
                string rank1 = c1.rankString(c1.getRank());

                myfile << p1.getName() << " asks - Do you have a " << rank1 << "?" << endl;

                if (p2.cardInHand(c1))  // if player 2 has a card of that rank
                {
                    myfile << p2.getName() << " says - Yes, I have a " << rank1 << endl;
                    p1.removeCardFromHand(c1);
                    c2 = p2.removeCardFromHand(c1); // card removed from player 2 and placed in this variable
                    p1.bookCards(c1, c2);

                    myfile << p1.getName() << " books the " << rank1 << endl;
                    myfile << endl;
                    myfile << endl;


                } else //player 2 does not have the card
                {
                    myfile << p2.getName() << " says - Go Fish! " << endl;

                    c2 = d.dealCard();
                    p1.addCard(c2);

                    myfile << p1.getName() << " draws a " << c2.toString() << endl;
                    myfile << endl;
                    myfile << endl;

                    if(p1.checkHandForBook(c1, c2))  //checks if there is a book after drawing
                    {
                        p1.removeCardFromHand(c1);
                        p1.removeCardFromHand(c2);

                        p1.bookCards(c1, c2);

                        myfile << p1.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
                        myfile << endl;
                        myfile << endl;
                    }

                }
            }



            //Player 2 Turn

            if(d.size() > 0 || p1.getHandSize() > 0 || p2.getHandSize() > 0)    // ONLY CONTINUE WITH PLAYER 2 IF THERE ARE CARDS REMAINING IN DECK OR IN HANDS
            {

                myfile << p1.getName() << " now has : " << p1.showHand() << endl;
                myfile << p2.getName() << " now has : " << p2.showHand() << endl;
                myfile << endl;
                myfile << endl;


                if (p2.getHandSize() <= 0)    //if hand is empty draw another and switch turns
                {

                    c1 = d.dealCard();
                    p2.addCard(c1);
                    myfile << p2.getName() << " draws a " << c1.toString() << endl;
                    myfile<<endl;


                } else {
                    c1 = p2.chooseCardFromHand();
                    string rank2 = c1.rankString(c1.getRank());

                    myfile << p2.getName() << " asks - Do you have a " << rank2 << "?" << endl;

                    if (p1.cardInHand(c1))  // if player 1 has a card of that rank
                    {
                        myfile << p1.getName() << " says - Yes, I have a " << rank2 << endl;
                        p2.removeCardFromHand(c1);
                        c2 = p1.removeCardFromHand(c1); // card removed from player 2 and placed in this variable
                        p2.bookCards(c1, c2);

                        myfile << p2.getName() << " books the " << rank2 << endl;
                        myfile << endl;
                        myfile << endl;
                    } else //player 1 does not have the card
                    {
                        myfile << p1.getName() << " says - Go Fish! " << endl;

                        c2 = d.dealCard();
                        p2.addCard(c2);

                        myfile << p2.getName() << " draws a " << c2.toString() << endl;
                        myfile << endl;
                        myfile << endl;
                        if (p2.checkHandForBook(c1, c2))  //places booked cards in c1 and c2
                        {
                            p2.removeCardFromHand(c1);
                            p2.removeCardFromHand(c2);

                            p2.bookCards(c1, c2);

                            myfile << p2.getName() << " books the " << c1.rankString(c1.getRank()) << endl;
                            myfile << endl;
                            myfile << endl;
                        }


                    }
                }
            }


            myfile << p1.getName() <<" now has : " << p1.showHand()<<endl;
            myfile << p2.getName() <<" now has : " << p2.showHand()<<endl;
            myfile << endl;
            myfile << endl;



        } //exit while loop when deck is empty

        myfile<<"GAME OVER!"<<endl;
        myfile<<endl;

        myfile<<p1.getName()<<" has books:  " << p1.showBooks()<<endl;  //can take out when we are done
        myfile<<endl;
        myfile<<p1.getName()<<" has " << p1.getBookSize() << " books."<<endl;
        myfile<<endl;

        myfile<<p2.getName()<<" has books:  " << p2.showBooks()<<endl;    //can take out when we are done
        myfile<<endl;
        myfile<<p2.getName()<<" has " << p2.getBookSize() << " books."<<endl;

        if(p1.getBookSize() > p2.getBookSize())
        {
            myfile<<endl;
            myfile<<p1.getName()<<" WINS!"<<endl;
        }
        else if(p2.getBookSize() > p1.getBookSize())
        {
            myfile<<endl;
            myfile<<p2.getName()<<" WINS!"<<endl;
        }
        else
        {
            myfile<<endl;
            myfile<<"ITS A TIE"<<endl;
        }







        myfile.close();

    }
    else
    {
        cout<<"No output file found"<<endl;
    }


    
    return EXIT_SUCCESS;  
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
      p.addCard(d.dealCard());
}

   



