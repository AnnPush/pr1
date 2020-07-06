/*(Card Shuffling and Dealing) Use the functions developed in previous exercise to
write a program that deals two five-card poker hands, evaluates each, and determines which is the
better hand.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2],  const char *wFace[], const char *wSuit[], unsigned int n1,  unsigned int f1); // dealing doesn't modify the arrays
int pair(unsigned int wHand[][2], const char *wFace[], const char *wSuit[]);

int main(void)
{
	 // initialize deck array
     unsigned int deck[SUITS][FACES] = {0};
     // represents hand
	 unsigned int hand[5][2];
	 unsigned int hand2[5][2];
	 unsigned int better, better2;
	  
	 srand(time(NULL)); // seed random-number generator
     shuffle(deck); // shuffle the deck

	 // initialize suit array
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // initialize face array
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

    printf("\nHand1\n\n");
	deal(deck, hand, face, suit, 1, 5); // deal the deck
	better = pair(hand, face, suit);
    printf("\nHand2\n\n");
	deal(deck, hand2, face, suit, 5, 10); // deal the deck
	better2 = pair(hand2, face, suit);

	if(better > better2)
	{
		printf("\nHand1 is the better hand\n");
	}
	else if(better < better2)
	{
        printf("\nHand2 is the better hand\n");
	}
	else
	{
		printf("\nHand2  = Hand2\n");
	}
    
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
void deal(unsigned int wDeck[][FACES], unsigned int wHand[][2], const char *wFace[], const char *wSuit[],  unsigned int n1,  unsigned int f1)
{
	 unsigned int r = 0;
     // deal each of the cards
     for (size_t card = n1; card <= f1; ++card)
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

int  pair(unsigned int wHand[][2],  const char *wFace[], const  char *wSuit[])
{
     unsigned int counter[FACES]={0};
     unsigned int counter1[SUITS]={0};
     unsigned int temp;

     size_t t = 0;
	 size_t m1 = 0;
	 size_t m2 = 0;
     
     for( size_t r = 0; r < 5; ++r)
     {
         ++counter[wHand[r][1]];
         ++counter1[wHand[r][0]];
     }
     
     for( size_t p = 0; p < FACES; ++p)
     {
         if(counter[p] == 2 )
         {
             t++;
			 if(t == 1)
			 {
				 m1 = p;
			 }
			 else if(t == 2)
			 {
				 m2 = p;
			 }
         }
         else if(counter[p] == 3 )
         {
             printf("\nThe hand contains a three %s\n", wFace[p] );
			 t = 3;
         }
         else if(counter[p] == 4 )
         {
             printf("\nThe hand contains a four %s\n", wFace[p] );
			 t = 4;
         }
     }
     
     if(t == 1)
     {
        printf("\nThe hand contains a pair %s\n", wFace[m1] );
	 }
     else if(t == 2)
     {
         printf("\nThe hand contains a two pairs %s and  %s\n", wFace[m1],wFace[m2]  );
     }


	 if( t == 0)
	 {
        for( size_t p = 0; p < SUITS; ++p)
        {  
		    if(counter1[p] == 5 )
            {
		        printf("\nThe hand contains a flush %s\n", wSuit[p] );
				t = 6;
		    }
	    }
	 }


     if( t == 0)
	 {
	    for( size_t i = 0; i < 5; ++i)
        {
		    for( size_t j = 0; j < 5; ++j)
            {
			    if(counter[j]> counter[j+1])
			    {
				    temp = counter[j];
				    counter[j] = counter[j+1];
				    counter[j+1] = temp;
			    }
		    }
	    }

       if(counter[4]-1 == counter[3] && counter[3]-1 == counter[2]&& counter[2]-1 == counter[1]&& counter[1]-1 == counter[0])
	   {
		   printf("The hand contains a straight from %s to %s/ \n", wFace[counter[0]], wFace[counter[4]]);
		   t = 5;
	   }
	 }
      return t;
}


