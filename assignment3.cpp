/*File:assignment4.cpp
*------------------------
*Name: Patrick Walter
*Username: x2010ogh
*Couse: CSci 162
*Purpose: ASsignment 4
*
*This program simulates 100 rounds of blackjack
*/



#include <iostream>
#include "deck.h"
#include "random.h"


int main()
{
int dealer, t, i=1, up, bust=0, deal=0, play=0;;
 //one deck is loaded and shuffled
Decks(1);

for (t=0; t<100; t++)
 {
 Randomize();
Shuffle();
//dealer draws two cards
card_t dcard1;
card_t dcard2;
dcard1=Draw();
dcard2=Draw();

//value of two cards is added to be dealers total
dealer = dcard1.value + dcard2.value;
//if dealers total value is less than 16 and another card is drawn and added
	while (dealer < 16 )
   		{
      	dcard1=Draw();
         dealer+= dcard1.value;
         }
  // if (dealer > 21)
    //	dealer = 0;

//player is given one card down
card_t carddown;
carddown = Draw();
//player is given room to have up to five cards up
card_t cardup[5];
//first card up is drawn
carddown = Draw();
cardup[1] = Draw();
DisplayCard(cardup[1]);


up = cardup[1].value;
//while value of cards up total is less than 6, drawn another card
//and adds it value
	while(up < 10)
      {
     	i++ ;
   	cardup[i]= Draw();
      up += cardup[i].value;
      DisplayCard(cardup[i]);
      }
      DisplayCard(carddown);
      up += carddown.value;
   if (up > 21)
   {
	  	cout << "bust" << endl;
      bust++;
   }

	else if ( up > dealer && up <=21 || dealer> 21)
   {
	  	cout << "player wins" << endl;
      play++;
    }

   else  if ( dealer >= up && dealer <=21)
   {
    	cout << "dealer wins"<< endl;
      deal++;
      }

   cout << up << " " << dealer << endl;
}

cout << " you win " << play << "% with " << bust << "% busts, and " << deal << "% dealer wins." ;


}














