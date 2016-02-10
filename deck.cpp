/* Filename: deck.cpp
 * ----------------------
 * Author:  M. van Bommel
 * Course:  CSci 162
 * Date:    16 February 2011
 * Purpose: Implementation file for deck.h - needs random to operate
 */

#include "deck.h"
#include "random.h"
#include <iostream>
#include <stdlib>

#define NumCards 52             // Number of cards in standard deck, no jokers

static card_t *deck;            // Deck of cards
static int  CardsLeft = 0;      // Num of cards remaining in deck = zero -> shuffle
static bool Randomized = 0;     // Only want to call Randomize once
static int  NumDecks = 1;       // Number of decks to use in pack (default is one)

/* Function: Decks
 * Usage:    Decks(n);
 * -------------------
 * Called before first call to shuffle to set the number of decks in the pack.
 */

extern void Decks(int n)
{
   if (Randomized)
   {
      cout << "Cannot reset number of decks.";
      exit (0);
   }
   NumDecks = n;
}

/* Function: Shuffle
 * -----------------
 * Fills array representing deck with numbers 0 to 51 and calls
 * randomize to seed the random number generator if necessary.
 * Sets the number of cards left to deal as NUMCARDS.
 */

extern void Shuffle(void)
{
   suit_t s;
   int val, d, i=0;

   if (!Randomized) {
      Randomize();
      Randomized = 1;
      deck = new card_t[NumDecks * NumCards];
      if (deck == NULL)
      {
         cout << "Out of memory - too many cards\n";
         exit(0);
      }
      for (d=0; d < NumDecks; d++)
      {
         for (s = Spades; s <= Diamonds; s++)
         {
            for (val=1; val < 14; val++)
      	    {
               deck[i].suit = s;
               deck[i].value = val;
               i++;
      	    }
         }
      }
   }
   CardsLeft = NumDecks * NumCards;
}

/* Function: Cards
 * ---------------
 * Returns the number of cards left to deal from the deck.
 */

extern int Cards(void)
{
   return (CardsLeft);
}

/* Function: Draw
 * --------------
 * Chooses a random card from deck, moves last card in deck to its position,
 * decrements size of remaining deck, and evaluates and returns the card.
 */

extern card_t Draw(void)
{
   int r;
   card_t card;

   if (!CardsLeft) {
      cout << "Deck is empty\n";
      card.value = 0;
      card.suit = Spades;
   } else {
      CardsLeft--;
      r = RandomInteger(0, CardsLeft);
      card = deck[r];
      deck[r] = deck[CardsLeft];           // swap with last card in deck
      deck[CardsLeft] = card;
   }
   return (card);
}



/* Function: DisplayCard
 * ---------------------
 * Displays the rank and suit of the given card.
 */

extern void DisplayCard(card_t card)
{
   switch (card.value)
   {
      case 1:  cout << 'A'; break;
      case 10: cout << 'T'; break;
      case 11: cout << 'J'; break;
      case 12: cout << 'Q'; break;
      case 13: cout << 'K'; break;
      default: cout << card.value;
   }
   switch (card.suit)
   {
      case Spades:   cout << 'S'; break;
      case Hearts:   cout << 'H'; break;
      case Clubs:    cout << 'C'; break;
      case Diamonds: cout << 'D'; break;
      default:       cout << '?';
   }
}


/* Function: DisplayHand
 * ---------------------
 * Displays the hand of size cards, separated by spaces.
 */

extern void DisplayHand(card_t hand[], int size)
{
   int i;
   for (i=0; i<size; i++) {
      DisplayCard(hand[i]);
      cout << ' ';
   }
}



/* Function: SortHandBySuit
 * -------------------------
 * Sorts a hand of size cards by suit (then by value), using a bubble sort.
 */

extern void SortHandBySuit(card_t hand[], int size)
{
   int i,j;

   for (j=size-1; j>0; j--)
      for (i=0; i<j; i++)
      	if ( hand[i].suit > hand[i+1].suit ||
             hand[i].suit == hand[i+1].suit &&
             hand[i].value > hand[i+1].value )

           SwapCards(&hand[i], &hand[i+1]);
}



/* Function: SortHandByValue
 * -------------------------
 * Sorts a hand of size cards by value, using a bubble sort.
 */

extern void SortHandByValue(card_t hand[], int size)
{
   int i,j;

   for (j=size-1; j>0; j--)
      for (i=0; i<j; i++)
      	 if (hand[i].value > hand[i+1].value )
            SwapCards(&hand[i], &hand[i+1]);
}



/* Function: SwapCards
 * -------------------
 * Swaps two cards in memory.
 */

extern void SwapCards(card_t *p1, card_t *p2)
{
   card_t temp;
   temp = *p1;
   *p1 = *p2;
   *p2 = temp;
}
