#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2], const char *wFace[], const char *wSuit[]); // dealing doesn't modify the arrays
void pair(unsigned int wHand[][2], const char *wFace[], const char *wSuit[]);

int main(void)
{
	 // initialize deck array
     unsigned int deck[SUITS][FACES] = {0};
     // represents hand
	 unsigned int hand[5][2];

	 srand(time(NULL)); // seed random-number generator
     shuffle(deck); // shuffle the deck

	 // initialize suit array
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // initialize face array
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

     deal(deck, hand, face, suit); // deal the deck
     pair(hand, face, suit);
}

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
     // for each of the cards, choose slot of deck randomly
     for (size_t card = 1; card <= CARDS; ++card)
	 {
         size_t row; // row number
         size_t column; // column number

         // choose new random location until unoccupied slot found
         do {
             row = rand() % SUITS;
             column = rand() % FACES;
         } while(wDeck[row][column] != 0); 

         // place card number in chosen slot of deck
         wDeck[row][column] = card;
     }
} 

// deal cards in deck
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2], const char *wFace[], const char *wSuit[])
{
	 unsigned int r = 0;
     // deal each of the cards
     for (size_t card = 1; card <= 5; ++card)
	 {
         // loop through rows of wDeck
         for (size_t row = 0; row < SUITS; ++row)
		 {
             // loop through columns of wDeck for current row
             for (size_t column = 0; column < FACES; ++column)
		     {
                 // if slot contains current card, display card
                 if (wDeck[row][column] == card) 
				 {
					 wHand[r][0] = row;
					 wHand[r][1] = column;
	                 printf("%5s of %-8s\n", wFace[column], wSuit[row]);
					 ++r;
                 }
             }
         }
     }
}

void pair(unsigned int wHand[][2],  const char *wFace[], const  char *wSuit[])
{
     unsigned int counter[FACES]={0};
     size_t t = 0;
     
     for( size_t r = 0; r < 5; ++r)
     {
         ++counter[wHand[r][1]];
     }
     
     for( size_t p = 0; p < FACES; ++p)
     {
         if(counter[p] == 2 )
         {
             t++;
         }
         else if(counter[p] == 3 )
         {
             printf("\nThe hand contains a three %s\n", wFace[p] );
         }
         else if(counter[p] == 4 )
         {
             printf("\nThe hand contains a four %s\n", wFace[p] );
         }
     }
     
     if(t == 1)
     {
        printf("\nThe hand contains a pair" );
	 }
     else if(t == 2)
     {
         printf("\nThe hand contains a two pairs" );
     }
}
