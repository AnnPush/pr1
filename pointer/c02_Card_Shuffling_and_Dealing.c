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
int pair(unsigned int wHand[][2], const char *wFace[], const char *wSuit[], unsigned int *mm, unsigned int *wHightCard);

int main(void)
{
	 // initialize deck array
     unsigned int deck[SUITS][FACES] = {0};
     // represents hand
	 unsigned int hand[5][2];
	 unsigned int hand2[5][2];

     unsigned int hightCard1[5];
	 unsigned int hightCard2[5];

	 unsigned int better, better2;
	 unsigned int mm1 = 0;
	 unsigned int mm2 = 0;
unsigned int flag = 0;

	 
	  
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
	better = pair(hand, face, suit, &mm1, hightCard1);
    printf("\nHand2\n\n");
	deal(deck, hand2, face, suit, 5, 9); // deal the deck
	better2 = pair(hand2, face, suit, &mm2, hightCard2);

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
		
		if(mm1>mm2)
		{
			printf("\nHand1 is the better hand\n");
		}
		else if(mm1<mm2)
		{
			printf("\nHand2 is the better hand\n");
		}
		else
		{
			for(size_t i =0 ; i < 5; ++i)
			{
				if( hightCard1[i] > hightCard2[i])
				{ 
					printf("\nHand1 is the better hand\n");
					flag=1;
					break;
				}
				else if (hightCard1[i] < hightCard2[i])
				{
					printf("\nHand2 is the better hand\n");
					flag = 1;
					break;

				}
				
			}
			if(flag == 0)
			{
				printf("\nHand1 = Hand2\n");
			}
			
		    
		}
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

int  pair(unsigned int wHand[][2],  const char *wFace[], const  char *wSuit[], unsigned int *mm, unsigned int *wHightCard)
{
	void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);
     unsigned int counter[FACES]={0};
     unsigned int counter1[SUITS]={0};
     unsigned int s[5] ={0};
     unsigned int w[5] ={0};
     unsigned int k1=0;
	 unsigned int k2 = 0;

     size_t t = 0;
	
     
     for(unsigned int r = 0; r < 5; ++r)
     {
         ++counter[wHand[r][1]];
         ++counter1[wHand[r][0]];
		 s[r] = wHand[r][1];
		 w[r] = wHand[r][1];
     }
     
     for( unsigned int p = 0; p < FACES; ++p)
     {
         if(counter[p] == 2 )
         {
             t++;
			 if(t == 1)
			 {
				 k1 = p;
			 }
			 else if(t == 2)
			 {
				 k2 = p;
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
			 t = 6;
         }
     }
     
     if(t == 1)
     {
        printf("\nThe hand contains a pair %s\n", wFace[k1] );
		*mm = k1;
		
		
	 }
     else if(t == 2)
     {
         printf("\nThe hand contains a two pairs %s and  %s\n", wFace[k1],wFace[k2]  );
		 *mm = k1 + k2;
     }


	 if( t == 0)
	 {
        for( size_t p = 0; p < SUITS; ++p)
        {  
		    if(counter1[p] == 5 )
            {
		        printf("\nThe hand contains a flush %s\n", wSuit[p] );
				
				t = 5;
		    }
	    }
		for (size_t i=0; i<5;++i )
		{
			*mm = w[0] + w[1] + w[2] + w[3] + w[4];
		}
	 }

     for( size_t i = 0; i < 4; ++i)
        {
		    for( size_t j = 0; j < 4; ++j)
            {
			    if(s[j]< s[j+1])
			    {
				    swap(&s[j], &s[j+1]);
			    }
				
		    }
	    }
		printf("\nSort:\n ");
		for( size_t i = 0; i < 5; ++i)
        {
			
			printf("%s\n ", wFace[s[i]] );
		}
		for( size_t i = 0; i < 5; ++i)
        {
           wHightCard[i] = s[i];
		   
		}

     if( t == 0)
	 {
	    

       if(s[4]-1 == s[3] && s[3]-1 == s[2] && s[2]-1 == s[1] && s[1]-1 == s[0])
	   {
		   printf("The hand contains a straight from %s to %s/ \n", wFace[s[0]], wFace[s[4]]);
		   *mm = s[0] + s[1] + s[2] + s[3] + s[4];
		   t = 4;
	   }
	 }
      return t;
}

void swap(unsigned int * element1Ptr, unsigned int * element2Ptr)
{
	unsigned int temp = * element1Ptr;
    * element1Ptr = * element2Ptr;
    * element2Ptr = temp;
}
