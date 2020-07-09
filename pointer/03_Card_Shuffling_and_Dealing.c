#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//ïðîòîòèïû
void shuffle(unsigned int wDeck[][FACES]); // òàñîâàòü êîëîäó êàðò
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *n1,  unsigned int *f1); // ðàçäàòü êàðòû íå èçìåíÿÿ ìàññèâ
int rating(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *nominal, unsigned int *wSortPlayer, unsigned int *comb);//îöåíêà êàðò


int main(void)
{
	 // èíèöèàëèçàöèÿ êîëîäû êàðò íóëÿìè
     unsigned int deck[SUITS][FACES] = {0};
     
	 unsigned int player1[5][2] = {{1, 2}, {0, 2}, {4, 2}, {5, 2}, {6, 2}};//êàðòû íà ðóêàõ ó ïåðâîãî èãðîêà
	 unsigned int player2[5][2]= {{8, 1}, {5, 1}, {0, 1}, {3, 1}, {8, 1}};//êàðòû íà ðóêàõ ó âòîðîãî èãðîêà
     

     unsigned int sortPlayer1[5];//ñîðòèðîâàííûé ìàññèâ êàðò íà ðóêàõ ó ïåðâîãî èãðîêà
	 unsigned int sortPlayer2[5];//ñîðòèðîâàííûé ìàññèâ êàðò íà ðóêàõ ó âòîðîãî èãðîêà

	 unsigned int combination1;//êîìáèíàöèÿ êàðò ïåðâîãî èãðîêà
	 unsigned int combination2;//êîìáèíàöèÿ êàðò âòîðîãî èãðîêà

	 unsigned int comb1 = 0;
     unsigned int comb2 = 0;

	 unsigned int nominal1 = 0;//ñóììà íîìèíàëîâ êàðò ïåðâîãî èãðîêà
	 unsigned int nominal2 = 0;//ñóììà íîìèíàëîâ êàðò âòîðîãî èãðîêà

	 unsigned int start = 1;
	 unsigned int finish = 5;
    

	 unsigned int flag = 0;//ñ÷åò÷èê ïðè îïðåäåëåíèè ñòàðøåé êàðòû, ñêîëüêî êàðò îêàçàëèñü ðàâíû

	 //çàñåÿòü ãåíåðàòîð ñëó÷àéíûõ ÷èñåë 
	 srand(time(NULL)); 
     //shuffle(deck); // òàñîâàòü êîëîäó

	 // èíèöèàëèçàöèÿ ìàññèâà ìàñòåé
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // èíèöèàëèçàöèÿ ìàññèâà íîìèíàëîâ(çíà÷åíèé)
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

     printf("\nHand1\n\n");

    
	 //ñäàòü êàðòû ïåðâîìó èãðîêó ñ 0 ïî 4
	 deal(deck, player1, face, suit, &start, &finish); 

	 printf("\nHand2\n\n");

     finish = 5;
	 //ñäàòü êàðòû âòîðîìó èãðîêó ñ 5 ïî 9
	 deal(deck, player2, face, suit, &start, &finish); 

     
	 //íàéòè êîìáèíàöèþ êàðò ïåðâîãî èãðîêà
	 combination1 = rating(player1, face, suit, &nominal1, sortPlayer1, &comb1);
    
	 //íàéòè êîìáèíàöèþ êàðò âòîðîãî èãðîêà
	 combination2 = rating(player2, face, suit, &nominal2, sortPlayer2, &comb2);

	 
}




// ïåðåòàñîâàòü êàðòû â êîëîäå
void shuffle(unsigned int wDeck[][FACES])
{
     // äëÿ êàæäîé èç 52 êàðò ñëó÷àéíî âûáðàòü ìåñòî â êîëîäå
     for (size_t card = 1; card <= CARDS; ++card)
	 {
         size_t row; // íîìåð ñòðîêò
         size_t column; // íîìåð ñòîëáöà

         // âûáðàòü íîâóþ ïîçèöèþ, ïîêà íå áóäåò íàéäåíà ñâîáîäíàÿ
         do {
             row = rand() % SUITS;
             column = rand() % FACES;
         } while(wDeck[row][column] != 0); 

         // ïîìåñòèòü íîìåð êàðòû â âûáðàííîå ìåñòî êîëîäû
         wDeck[row][column] = card;
     }
} 

// ñäàòü êàðòû
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[],  unsigned int *n1,  unsigned int *f1)
{
	 unsigned int r = 0;//ñ÷åò÷èê îïðåäåëÿþùèé íîìèíàë è ìàñòü êàðò
     
	 *f1 += *n1;
	
     // ñäàòü êàðòû â óêàçàííûõ ïðåäåëàõ
     for (size_t card = *n1; card < *f1 ; ++card)
	 {
         // öèêë ïî ñòðîêàì
         for (size_t row = 0; row < SUITS; ++row)
		 {
             // öèêë ïî ñòîëáöàì â òåêóùåé ñòðîêå
             for (size_t column = 0; column < FACES; ++column)
		     {
                 // åñëè ÿ÷åéêà ñîäåðæèò òåêóùóþ êàðòó, âûâåñòè åå
                 if ( wPlayer[row][column] == card) 
				 {
					 wPlayer[r][0] = row;//çàïîìíèòü ìàñòü êàðòû, ïîëó÷åííîé èãðîêîì
					 wPlayer[r][1] = column;//çàïîìíèòü íîìèíàë êàðòû, ïîëó÷åííîé èãðîêîì
	                 printf("%5s of %-8s\n", wFace[column], wSuit[row]);//ïå÷àòü êàðòû, ïîëó÷åííîé èãðîêîì 
					 ++r;
                 }
             }
         }
     }
	*n1 = *f1 ;
	printf("\n*n1=%d\n",*n1);
}

//îöåíêà êàðò
int  rating(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int *nominal, unsigned int *wSortPlayer, unsigned int *comb)
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
		 wSortPlayer[r] = wPlayer[r][1];//çàïîëíÿåì ìàññèâ íîìèíàëîâ êàðò, êîòîðûå íà ðóêàõ ó èãðîêà
		
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
         else if(counter[p] == 3 )//åñëè íà ðóêàõ òðè îäèíàêîâûå êàðòû
         {
             printf("\nThe hand contains a three %s\n", wFace[p] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
			 t = 3;//ïðèîðèòåò êîìáèíàöèè
			  *comb = 7;
         }
         else if(counter[p] == 4 )//ååñëè íà ðóêàõ ÷åòûðå îäèíàêîâûå êàðòû
         {
             printf("\nThe hand contains a four %s\n", wFace[p] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
			 t = 6;//ïðèîðèòåò êîìáèíàöèè
			 *comb = 10;
         }
     }
     
     if(t == 1)//åñëè íà ðóêàõ îäíà ïàðà
     {
        printf("\nThe hand contains a pair %s\n", wFace[k1] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
		*nominal = k1;//çàïîìíèòü íîìèíàë ïåðâîé ïàðû
		 *comb = 5;
		
	 }
     else if(t == 2)//åñëè íà ðóêàõ äâå ïàðû
     {
         printf("\nThe hand contains a two pairs %s and  %s\n", wFace[k1],wFace[k2]  );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
		 *nominal = k1 + k2;//ñ÷èòàåì ñóììó íîìèíàëîâ äâóõ ïàð
		  *comb = 6;
     }

     //ñîðòèðîâêà ìàññèâà êàðò, êîòîðûå èìåþòñÿ íà ðóêàõ ó èãðîêà
     for( size_t i = 0; i < 4; ++i)
     {
		 for( size_t j = 0; j < 4; ++j)
         {
			 if(wSortPlayer[j] < wSortPlayer[j+1])
			 {
				 swap(&wSortPlayer[j], &wSortPlayer[j+1]);//îáìåí ýëåìåíòîâ
			 }		
		 }
	 }

     //òåñòèðîâàíèå ïðîãðàììû
	 printf("\nSort:\n ");
	 for( size_t i = 0; i < 5; ++i)
     {		
		  printf("%s\n ", wFace[ wSortPlayer[i]] );
	 }
	 
	 //åñëè îäèíàêîâûõ íîìèíàëîâ êàðò íà ðóêàõ ó èãðîêà íåò, ïðîâåðÿåì êîìáèíàöèþ ôëåø(ïÿòü êàðò îäíîé ìàñòè)
	 if( t == 0)
	 {
        for( size_t p = 0; p < SUITS; ++p)
        {  
		    if(counter1[p] == 5 )//åñëè ïÿòü êàðò îäíîé ìàñòè
            {
		        printf("\nThe hand contains a flush %s\n", wSuit[p] );//âûâîäèì ñîîáùåíèå è ìàñòü êàðòû íà ýêðàí
				
				t = 5;//ïðèîðèòåò êîìáèíàöèè
				 *comb = 9;
		    }
			 //Ñòðèò: îïðåäåëèòü, èäóò ëè êàðòû ïî ïîðÿäêó, íî ìàñòè ðàçíûå
			if(wSortPlayer[4]-1 == wSortPlayer[3] && wSortPlayer[3]-1 == wSortPlayer[2] && wSortPlayer[2]-1 == wSortPlayer[1] && wSortPlayer[1]-1 == wSortPlayer[0])
	        {
		       printf("The hand contains a straight from %s to %s \n", wFace[wSortPlayer[0]], wFace[wSortPlayer[4]]);
		       for (size_t i = 0; i < 5; ++i )
		       {
			       *nominal += wSortPlayer[i];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè
		       }
		       t = 4;
		       *comb = 8;
	        }
	        else if(wSortPlayer[4]-1 == wSortPlayer[3] && wSortPlayer[3]-1 == wSortPlayer[2] && wSortPlayer[2]-1 == wSortPlayer[1])
	        {
               // printf("\nThe hand contains a StraightDro from %s to %s \n", wFace[wSortPlayer[0]], wFace[wSortPlayer[3]]);//âûâîäèì ñîîáùåíèå è ìàñòü êàðòû íà ýêðàí
                *comb = 3;
	         }
			if(counter1[p] == 4 )//åñëè 4 êàðò îäíîé ìàñòè
            {
				if(*comb == 3)
				{
					*comb = 1;
				}
				else
				{
				printf("\nThe hand contains a FlushDro %s\n", wSuit[p] );//âûâîäèì ñîîáùåíèå è ìàñòü êàðòû íà ýêðàí
                *comb = 4;
				}
			}
			else if(*comb == 3)
			{
                    printf("\nThe hand contains a StraightDro from %s to %s \n", wFace[wSortPlayer[0]], wFace[wSortPlayer[3]]);//âûâîäèì ñîîáùåíèå è ìàñòü êàðòû íà ýêðàí
			}
	    }
		for (size_t i = 0; i < 5; ++i )
		{
			*nominal += wSortPlayer[i];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè
		}
       
	 }

     


    
     if( t == 0)
	 {	    
       
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
