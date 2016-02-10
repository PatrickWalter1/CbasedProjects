/* Filename: deck.h
 * ----------------
 * Author:  M. van Bommel
 * Course:  CSci 162
 * Date:    16 February 2011
 *
 * Interface file for a standard deck of cards without jokers.
 *
 * Must call Shuffle() before any others or no cards can be dealt.
 *
 * Mode of use is typically:
 *
 *    card_t card;
 *    Shuffle();
 *    while (Cards()) {
 *       card = Draw();
 *       DisplayCard(card);
 *    }
 *
 * Also has functions to Display a hand of cards stored in an array,
 * and to sort the hand by suit and value or just by value.
 *
 * If more than one deck is desired, call Decks(n) before calling Shuffle.
 */

#ifndef _deck_h
#define _deck_h


typedef enum {                          // card suits
   Spades, Hearts, Clubs, Diamonds
} suit_t;


typedef struct {                        // card structure
   int value;
   suit_t suit;
} card_t;


/* Function: Decks
 * Usage:    Decks(n);
 * -------------------
 * Called before first call to shuffle to change the number of decks used
 * in the pack - default is one deck if not called.
 */

extern void Decks(int n);


/* Function: Shuffle
 * Usage:    Shuffle();
 * --------------------
 * Shuffles the deck of cards, making all of them available for dealing,
 * or resets the deck after dealing some of them.
 */

extern void Shuffle(void);


/* Function: Cards
 * Usage:    n = Cards();
 * ----------------------
 * Returns the number of cards remaining in the deck.
 */

extern int Cards(void);


/* Function: Draw
 * Usage:    card = Draw();
 * ---------------------------
 * Selects the top card off of the deck, and returns it.
 */

extern card_t Draw(void);



/* Function: DisplayCard
 * Usage:    DisplayCard(card);
 * ----------------------------
 * Displays the rank and suit of the given card.
 * Displays rank as A, 1, 2, ... , 9, T, J, Q, K.
 * Displays suit as S (Spades), C (Clubs), H (Hearts), or D (Diamonds).
 */

extern void DisplayCard(card_t card);


/* Function: DisplayHand
 * ---------------------
 * Displays the hand of size cards stored in an array, separated by spaces.
 */

extern void DisplayHand(card_t hand[], int size);


/* Function: SortHandBySuit
 * -------------------------
 * Sorts a hand of size cards by suit (then by value within the suit).
 */

extern void SortHandBySuit(card_t hand[], int size);


/* Function: SortHandByValue
 * -------------------------
 * Sorts a hand of size cards by value.
 */

extern void SortHandByValue(card_t hand[], int size);


/* Function: SwapCards
 * -------------------
 * Swaps two cards in memory.
 */

extern void SwapCards(card_t *p1, card_t *p2);

#endif
