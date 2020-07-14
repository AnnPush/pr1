#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//ïðîòîòèïû
void shuffle(unsigned int wDeck[][FACES]); // òàñîâàòü êîëîäó êàðò
int rating(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *nominal);//îöåíêà êàðò
int printRating(unsigned int*, unsigned int*);//ïå÷àòü ðåçóëüòàòà îöåíèâàíèÿ êàðò
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *n1,  unsigned int *f1); // ðàçäàòü êàðòû íå èçìåíÿÿ ìàññèâ
int main(void)
{
	 // èíèöèàëèçàöèÿ êîëîäû êàðò 
     unsigned int deck[SUITS][FACES] = { 28,  27, 31, 32,  33, 22, 19, 14,  17, 24, 21, 20, 26, 6, 7, 10, 30, 8, 12, 9, 29,  15, 11,  13,  16, 18, 2, 1, 3, 4, 23, 25, 34, 35, 36, 37, 38, 39, 40, 41,  42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 5, 52 };
     
	 unsigned int player1[5][2]; //= {{1, 2}, {0, 2}, {4, 2}, {5, 2}, {6, 2}};//êàðòû íà ðóêàõ ó ïåðâîãî èãðîêà
	 unsigned int player2[5][2]; //= {{8, 1}, {5, 1}, {0, 1}, {3, 1}, {10, 1}};//êàðòû íà ðóêàõ ó âòîðîãî èãðîêà
   
	 unsigned int combination1;//êîìáèíàöèÿ êàðò ïåðâîãî èãðîêà
	 unsigned int combination2;//êîìáèíàöèÿ êàðò âòîðîãî èãðîêà

	 unsigned int nominal1 = 0;//ñóììà íîìèíàëîâ êàðò ïåðâîãî èãðîêà
	 unsigned int nominal2 = 0;//ñóììà íîìèíàëîâ êàðò âòîðîãî èãðîêà

	  unsigned int start = 1;
	 unsigned int finish = 5;
    

	 unsigned int flag = 0;//ñ÷åò÷èê ïðè îïðåäåëåíèè ñòàðøåé êàðòû, ñêîëüêî êàðò îêàçàëèñü ðàâíû
 
	 

	 // èíèöèàëèçàöèÿ ìàññèâà ìàñòåé
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // èíèöèàëèçàöèÿ ìàññèâà íîìèíàëîâ(çíà÷åíèé)
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

//shuffle(deck);
 printf("\nHand1\n\n");
deal(deck, player1, face, suit, &start, &finish); 
 combination1 = rating(player1, face, suit, &nominal1);

 printf("\nHand2\n\n");
 finish = 5;
	 //ñäàòü êàðòû âòîðîìó èãðîêó ñ 5 ïî 9
	 deal(deck, player2, face, suit, &start, &finish); 
	  combination2 = rating(player2, face, suit, &nominal2);


	 if(combination1 > 3 && combination1 < 7)
	{
		 puts("No cards!");
	}
   if(combination1 == 1 || combination1 == 0)
	{
           puts("3 cards!");
finish = 3;
	}
	else if(combination1 == 3)
	{
		 puts("2 cards!");
		 finish = 2;
	}
	else if(combination1 == 2 || combination1 == 7 || combination1 == 8 || combination1 == 9)
	{
        puts("1 card!");
		finish = 1;
	}



	 deal(deck, player1, face, suit, &start, &finish); 
for (size_t i = 0; i < 5; ++i)
{
	
     printf("\nplayer1 %d\n", player1[i][1] );

}



	/*

	 //íàéòè êîìáèíàöèþ êàðò âòîðîãî èãðîêà
	 combination2 = rating(player2, face, suit, &nominal2, sortPlayer2);*/


/*	 if(combination1 > 6)
	{
	 combination1 = 0;
	}
if(combination2 > 6)
	{
	 combination2 = 0;
	}
	 //ïå÷àòü ðåçóëüòàòà îöåíèâàíèÿ êàðò
	 if(!printRating(&combination1, &combination2))//ñðàâíèòü êîìáèíàöèè êàðò
	 {
		 if(!printRating(&nominal1, &nominal2))//åñëè êîìáèíàöèè ðàâíû, ñðàâíèòü íîìèíàëû
		 {
			 for(size_t i =0 ; i < 5; ++i)
			 {
				 if(!printRating(&sortPlayer1[i], &sortPlayer2[i]))//åñëè íîìèíàëû ðàâíû, ñðàâíåíèå èäåò ïî ñîðòèðîâàííîìó ìàññèâó ïî ñòàðøåé êàðòå
		         {
					 flag++;
				 }
				 if( flag == 5)
				 {
                     printf("\nHand1 = Hand2\n");//êàðòû èãðîêîâ ðàâíû
			     }
			 }
		}
	}  */
}
/*void shuffle(unsigned int wDeck[][FACES])
{
	const char fa[52] = {1, 0, 4, 5, 6, 8, 5, 0, 3, 10, 0, 1, 7, 12, 11, 9, 4, 1, 7, 8, 12, 2, 4, 12, 6, 0, 6, 8, 3, 10, 2, 11, 11, 5, 2, 12, 6, 3, 3, 7, 11, 10, 2, 1, 4, 9, 9, 5, 8, 9, 7, 10};
    const char su[52] = {2, 2, 2, 2, 2, 1, 1, 1, 1, 1,  0, 0, 3, 3,   0, 2, 0, 3, 2, 0, 2,  1, 3, 0,  0, 3, 1, 3, 2, 3,  0, 1,   3, 0, 2, 1,  3, 0, 3, 1,  2,  2, 3, 1, 1, 0, 3, 3, 2, 1, 0, 0};
	 wDeck[4][12] = {28, 27, 31, 32, 33, 22, 19, 14, 17, 24, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
     // äëÿ êàæäîé èç 52 êàðò ñëó÷àéíî âûáðàòü ìåñòî â êîëîäå
     
        
    
} */
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[],  unsigned int *n1,  unsigned int *f1)
{
	 unsigned int r = 0;//ñ÷åò÷èê îïðåäåëÿþùèé íîìèíàë è ìàñòü êàðò
  *f1 += *n1;
     // ñäàòü êàðòû â óêàçàííûõ ïðåäåëàõ
     for (size_t card = *n1; card < *f1; ++card)
	 {
         // öèêë ïî ñòðîêàì
		 
         for (size_t row = 0; row < SUITS; ++row)
		 {
             // öèêë ïî ñòîëáöàì â òåêóùåé ñòðîêå
             for (size_t column = 0; column < FACES; ++column)
		     {
				 
				 if (wDeck[row][column] == card) 
				 {

	
                 wPlayer[r][0] = row;//çàïîìíèòü ìàñòü êàðòû, ïîëó÷åííîé èãðîêîì
					 wPlayer[r][1] = column;//çàïîìíèòü íîìèíàë êàðòû, ïîëó÷åííîé èãðîêîì
				  printf("%5s of %-8s\n", wFace[column], wSuit[row]);
				  ++r;
				 
	            }
                
            }
	
        }
	 }
	*n1 = *f1 ;
}

//îöåíêà êàðò
int  rating(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int *nominal)
{
	 void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);//ôóíêöèÿ îáìåíèâàþùàÿ êàðòû â ÿ÷åéêàõ, íà êîòîðûå ïîêàçûâàþò óêàçàòåëè

     unsigned int counter[FACES]={0};//ñêîëüêî îäèíàêîâûõ íîìèíàëîâ êàðò íà ðóêàõ ó èãðîêà
     unsigned int counter1[SUITS]={0};//ñêîëüêî îäèíàêîâûõ ìàñòåé êàðò íà ðóêàõ ó èãðîêà
     
     unsigned int k1 = 0;//ïåðåìåííàÿ äëÿ çàïîìèíàíèÿ íîìèíàëà ïåðâîé ïàðû êàðò
	 unsigned int k2 = 0;//ïåðåìåííàÿ äëÿ çàïîìèíàíèÿ íîìèíàëà âòîðîé ïàðû êàðò

     size_t t = 0;//ïðèîðèòåò êîìáèíàöèè
	
     
     for(unsigned int r = 0; r < 5; ++r)
     {
         ++counter[wPlayer[r][1]];//ñ÷èòàåì, ñêîëüêî îäèíàêîâûõ íîìèíàëîâ êàðò íà ðóêàõ ó èãðîêà
         ++counter1[wPlayer[r][0]];//ñ÷èòàåì, ñêîëüêî îäèíàêîâûõ ìàñòåé êàðò íà ðóêàõ ó èãðîêà	
     }
     
     for( unsigned int p = 0; p < FACES; ++p)
     {
         if(counter[p] == 2 )//åñëè äâå îäèíàêîâûå êàðòû
         {
             t++;//óâåëè÷èâàåì ñ÷åò÷èê íà åäèíèöó, òàê êàê íà ðóêàõ  ïàðà êàðò
			 if(t == 1)//åñëè íà ðóêàõ îäíà ïàðà
			 {
				 k1 = p;//çàïîìèíàåì íîìèíàë ïåðâîé ïàðû
			 }
			 else if(t == 2)//åñëè íà ðóêàõ äâå ïàðû
			 {
				 k2 = p;//çàïîìèíàåì íîìèíàë âòîðîé ïàðû
			 }
         }
		// ---------------------------3------------------------------
         else if(counter[p] == 3 )//åñëè íà ðóêàõ òðè îäèíàêîâûå êàðòû
         {
             printf("\nThe hand contains a three %s\n", wFace[p] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
			 t = 3;//ïðèîðèòåò êîìáèíàöèè
         }
		 // ---------------------------6------------------------------
         else if(counter[p] == 4 )//ååñëè íà ðóêàõ ÷åòûðå îäèíàêîâûå êàðòû
         {
             printf("\nThe hand contains a four %s\n", wFace[p] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
			 t = 6;//ïðèîðèòåò êîìáèíàöèè
         }
     }
     // --------------------------1----------------------------
     if(t == 1)//åñëè íà ðóêàõ îäíà ïàðà
     {
        printf("\nThe hand contains a pair %s\n", wFace[k1] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
		*nominal = k1;//çàïîìíèòü íîìèíàë ïåðâîé ïàðû
		
		
	 }
	 // ---------------------------2------------------------------
     else if(t == 2)//åñëè íà ðóêàõ äâå ïàðû
     {
         printf("\nThe hand contains a two pairs %s and  %s\n", wFace[k1],wFace[k2]  );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
		 *nominal = k1 + k2;//ñ÷èòàåì ñóììó íîìèíàëîâ äâóõ ïàð
     }
// ---------------------------5(FLASH)------------------------------
     //åñëè îäèíàêîâûõ íîìèíàëîâ êàðò íà ðóêàõ ó èãðîêà íåò, ïðîâåðÿåì êîìáèíàöèþ ôëåø(ïÿòü êàðò îäíîé ìàñòè)
	 if( t == 0)
	 {
        for( size_t p = 0; p < SUITS; ++p)
        {  
		    if(counter1[p] == 5 )//åñëè ïÿòü êàðò îäíîé ìàñòè
            {
		        printf("\nThe hand contains a flush %s\n", wSuit[p] );//âûâîäèì ñîîáùåíèå è ìàñòü êàðòû íà ýêðàí
				
				t = 5;//ïðèîðèòåò êîìáèíàöèè
		    }
			// ---------------------------7(FLASH_DRO)------------------------------
            else if(counter1[p] == 4 )
			{
                t = 7;//ïðèîðèòåò êîìáèíàöèè
				 //printf("\nThe hand contains a flush DRO %s\n", wSuit[p] );//âûâîäèì ñîîáùåíèå è ìàñòü êàðòû íà ýêðàí
			}
	    }
		for (size_t i = 0; i < 5; ++i )
		{
			*nominal += wPlayer[i][1];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè

		}
		printf("\nNominal %d\n", *nominal );
       // printf("\nNominal_flash %d\n", *nominal );
	 }

     //ñîðòèðîâêà ìàññèâà êàðò, êîòîðûå èìåþòñÿ íà ðóêàõ ó èãðîêà
     for( size_t i = 0; i < 4; ++i)
     {
		 for( size_t j = 0; j < 4; ++j)
         {
			 if(wPlayer[j][1] < wPlayer[j + 1][1])
			 {
				 swap(&wPlayer[j][1], &wPlayer[j + 1][1]);//îáìåí ýëåìåíòîâ
			 }		
		 }
	 }

     //òåñòèðîâàíèå ïðîãðàììû
	 printf("\nSort:\n ");
	 for( size_t i = 0; i < 5; ++i)
     {		
		  printf("%5s of %-8s\n ", wFace[ wPlayer[i][1]],  wSuit[ wPlayer[i][0]] );
	 }

// ---------------------------4(STRAIGHT)------------------------------
     //îïðåäåëèòü, èäóò ëè êàðòû ïî ïîðÿäêó, íî ìàñòè ðàçíûå
     	    
       if(wPlayer[4][1]+1 == wPlayer[3][1] && wPlayer[3][1]+1 == wPlayer[2][1] && wPlayer[2][1]+1 == wPlayer[1][1] && wPlayer[1][1]+1 == wPlayer[9][1])
	   {
		   printf("\nThe hand contains a straight from %s to %s .\n", wFace[wPlayer[4][1]], wFace[wPlayer[0][1]]);
		   for (size_t i = 0; i < 5; ++i )
		   {
			   *nominal += wPlayer[i][1];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè
		   }
		   t = 4;
	   }
	   // ---------------------------8(STRAIGHT_DRO)------------------------------
	   else if(wPlayer[4][1]+1 == wPlayer[3][1] && wPlayer[3][1]+1 == wPlayer[2][1] && wPlayer[2][1]+1 == wPlayer[1][1] || wPlayer[3][1]+1 == wPlayer[2][1] && wPlayer[2][1]+1 == wPlayer[1][1] && wPlayer[1][1]+1 == wPlayer[0][1])
		 {
 // ---------------------------9(COMBO_DRO)------------------------------
		   if(t == 0)
			 {
			   printf("The hand contains a STRAIGHT DRO\n");
		        t = 8;
			 }
			  else if(t == 7)
			 {
			   printf("The hand contains a COMBO DRO\n");
			   t == 9;
			 }
			
		 }
		 else if(t == 7)
	     {
			  
				 printf("\nThe hand contains a flush DRO \n" );
                
			 
	     }
	 
      return t;
}
//ôóíêöèÿ îáìåíèâàþùàÿ êàðòû â ÿ÷åéêàõ, íà êîòîðûå ïîêàçûâàþò óêàçàòåëè
void swap(unsigned int * element1Ptr, unsigned int * element2Ptr)
{
	unsigned int temp = * element1Ptr;
    * element1Ptr = * element2Ptr;
    * element2Ptr = temp;
}

//ïå÷àòü ðåçóëüòàòà îöåíèâàíèÿ êàðò
int printRating(unsigned int* ptr1, unsigned int* ptr2)
{
	if(*ptr1 > *ptr2)
	 {
		 printf("\nHand1 is the better hand\n");
		 return 1;
	 }
	 else if(*ptr1 < *ptr2)
	 {
         printf("\nHand2 is the better hand\n");
		 return 1;
	 }
   return 0;
}
