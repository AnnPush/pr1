#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//ïðîòîòèïû
void shuffle(unsigned int wDeck[][FACES]); // òàñîâàòü êîëîäó êàðò
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *n1,  unsigned int *f1); // ðàçäàòü êàðòû, íå èçìåíÿÿ ìàññèâ
int combination(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *nominal, unsigned int *kk1, unsigned int *kk2);//îïðåäåëèòü êîìáèíàöèþ êàðò
void printArray(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int pd);//ðàñïå÷àòàòü êàðòû èãðîêà
void printCombination(unsigned int tt);//ðàñïå÷àòàòü êîìáèíàöèþ
void takeCards(unsigned int wPlayer[][2], unsigned int *nominal, unsigned int tt, unsigned int *kk1, unsigned int *kk2, unsigned int *f1);//îïðåäåëèòü, ñêîëüêî êàðò âçÿòü åùå


int main(void)
{
	 //1_ èíèöèàëèçàöèÿ êîëîäû êàðò íóëÿìè(ïðè òåñòèðîâàíèè çàêîììåíòèðîâàòü ýòó ñòðîêó è âûáðàòü îäíó èç ïîñëåäóþùèõ)
	  unsigned int deck[SUITS][FACES] = {0};

	 unsigned int player1[5][2]; //êàðòû íà ðóêàõ ó ïåðâîãî èãðîêà
	 unsigned int player2[5][2]; //êàðòû íà ðóêàõ ó âòîðîãî èãðîêà
   
	 unsigned int combination1;//êîìáèíàöèÿ êàðò ïåðâîãî èãðîêà
	 unsigned int combination2;//êîìáèíàöèÿ êàðò âòîðîãî èãðîêà

	 unsigned int nominal1 = 0;//ñóììà íîìèíàëîâ êàðò ïåðâîãî èãðîêà
	 unsigned int nominal2 = 0;//ñóììà íîìèíàëîâ êàðò âòîðîãî èãðîêà

	 unsigned int start = 1;
	 unsigned int finish = 5;
    
	 unsigned int flag = 0;//ñ÷åò÷èê ïðè îïðåäåëåíèè ñòàðøåé êàðòû, ñêîëüêî êàðò îêàçàëèñü ðàâíû
     unsigned int pl_dl = 0;//åñëè äèëåð - 1, åñëè èãðîê -0 

	 unsigned int k1 = 100;//ïåðåìåííàÿ äëÿ çàïîìèíàíèÿ íîìèíàëà ïåðâîé ïàðû êàðò
	 unsigned int k2 = 100;//ïåðåìåííàÿ äëÿ çàïîìèíàíèÿ íîìèíàëà âòîðîé ïàðû êàðò
     
	 // èíèöèàëèçàöèÿ ìàññèâà ìàñòåé
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // èíèöèàëèçàöèÿ ìàññèâà íîìèíàëîâ(çíà÷åíèé)
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
     
	 //çàñåÿòü ãåíåðàòîð ñëó÷àéíûõ ÷èñåë 
	 srand(time(NULL)); 
	 //òàñîâàòü êîëîäó êàðò
     shuffle(deck);

     //ñäàòü êàðòû ïåðâîìó èãðîêó
     printf("\nHand1-------------------\n\n");
     deal(deck, player1, face, suit, &start, &finish); 
     printArray(player1, face, suit, 1); 

     //ñäàòü êàðòû âòîðîìó èãðîêó
     printf("\nHand2-------------------\n\n");
     finish = 5;
	 deal(deck, player2, face, suit, &start, &finish);
     printArray(player2, face, suit, 0);

	 printf("\nHand1-------------------\n");
	 combination1 = combination(player1, face, suit, &nominal1, &k1, &k2);
	 //printArray(player1, face, suit, 0);
	// printCombination(combination1);
	 takeCards(player1, &nominal1, combination1, &k1, &k2, &finish);
    // printArray(player1, face, suit, 0);
	 if(finish != 0)
	 {
		 deal(deck, player1, face, suit, &start, &finish); 
		 //printf("\nNew_array-------------------\n");
		 //printArray(player1, face, suit, 0);
	 }
	 combination1 = combination(player1, face, suit, &nominal1, &k1, &k2);
	// printCombination(combination1);

	 printf("\nHand2-------------------\n\n");
	 combination2 = combination(player2, face, suit, &nominal2, &k1, &k2);
	 printArray(player2, face, suit, 0);
	 printCombination(combination2);
}

//îïðåäåëèòü, ñêîëüêî êàðò âçÿòü åùå
void takeCards(unsigned int wPlayer[][2], unsigned int *nominal, unsigned int tt, unsigned int *kk1, unsigned int *kk2, unsigned int *f1)
{
	unsigned int wSortPlayer[5][2] = {0};//âðåìåííûé ìàññèâ
	unsigned int x = 0;//ñ÷åò÷èê äëÿ êàðò, êîòîðûå áóäóò îáìåíèâàòüñÿ
	unsigned int m = 0;//ñ÷åò÷èê êàðò, êîòîðûå ñîñòàâëÿþò êîìáèíàöèþ
	
    if( tt < 7 && tt > 3)//åñëè âûïàëî 4 îäèíàêîâûå êàðòû, ôëåø, ñòðèò
	{
		m = 0;//áåðåì 0 êàðò
	}
	else if(tt == 0 || tt == 1)//åñëè íåò êîìáèíàöèè èëè âûïàëà 1 ïàðà
	{
		m = 3;//áåðåì 3 êàðòû
	}
	else if(tt == 3)//åñëè âûïàëî 3 êàðòû
	{
		m = 2;//áåðåì 2 êàðòû
	}
	else//â îñòàëüíûõ ñëó÷àÿõ
	{
		m = 1;//áåðåì 1 êàðòó
	} 
	*f1 = m;//çàïîìèíàåì êîëè÷åñòâî êàðò, êîòîðûå áóäóò âçÿòû
    printf("\nTake %u cards!\n\n", m);

	if(tt > 7 && wPlayer[0][1] + 1 != wPlayer[1][1])//åñëè ñòðèò äðî, êîìáî äðî è ïåðâàÿ êàðòà íå âõîäèò â êîìáèíàöèþ, òî íè÷åãî íå ìåíÿåì
	{
		puts("");
	}
	else if(tt > 6 || tt < 4)//âñå âàðèàíòû, êðîìå ôëåø, 4 êàðòû, ñòðèò
    {
       for( size_t i = 0; i < 5; ++i)
	   {
		     if(tt > 7 && i == 0 && wPlayer[0][1] + 1 == wPlayer[1][1])//åñëè ñòðèò äðî, êîìáî äðî è ïåðâàÿ êàðòà  âõîäèò â êîìáèíàöèþ, òî ïîñëåäíÿÿ êàðòà ñòàíîâèòñÿ ïåðâîé
	        {
			    wSortPlayer[0][1] = wPlayer[4][1];
			    wSortPlayer[0][0] = wPlayer[4][0];
			}
            else if( (tt == 7 && wPlayer[i][0] != *kk1) || (tt < 7 && wPlayer[i][1] != *kk1 && wPlayer[i][1] != *kk2) )//åñëè ôëåø äðî è ýëåìåíò ìàññèâà ðàâåí íîìèíàëó êîìáèíàöèè èëè êîìáèíàöèÿ ìåíüøå ôëåø äðî è ýëåìåíò ìàññèâà íå ðàâåí íîìèíàëó êîìáèíàöèè
		    {
				//êàðòà îòïðàâëÿåòñÿ â íà÷àëî ìàññèâà
			    wSortPlayer[x][1] = wPlayer[i][1];
				wSortPlayer[x][0] = wPlayer[i][0];
			    x++;
		    }
			else 
		    { 
				if(tt > 7 && m == 1 )//åñëè ñòðèò äðî èëè êîìáî äðî, òî êàðòó ïåðåäâèãàåì íà îäíó ïîçèöèþ âíèç
				{
				    i = i - 1;
				}
				wSortPlayer[m][1] = wPlayer[i][1];
				wSortPlayer[m][0] = wPlayer[i][0];
				++m;
		    }
	   }
	   //ïåðåçàâèñàòü èç âðåìåííîãî ìàññèâà êàðòû
	   for( size_t i = 0; i < 5; ++i)
	   {
	        wPlayer[i][1]=wSortPlayer[i][1];
	        wPlayer[i][0]=wSortPlayer[i][0];
	   }
	}
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
     *f1 += *n1;//îïðåäåëèòü êîíå÷íóþ êàðòó ïðè ðàçäà÷å

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
					 ++r; 
	            }   
            }
        }
	 }
	 *n1 = *f1;//îïðåäåëåëèòü ïåðâóþ êàðòó ïðè ñëåäóþùåé ðàçäà÷å êàðò
}

//ðàñïå÷àòàòü êàðòû èãðîêà
void printArray(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int pd)
{
	for( size_t i = 0; i < 5; ++i)
    {		
	     if(pd == 0)
	     {
		     printf("%5s of %-8s\n ", wFace[ wPlayer[i][1]],  wSuit[ wPlayer[i][0]] );
	     }
	     else
	     {
             printf("%s\n","***");
	     }
    }
    printf("\n ");
}

//îïðåäåëÿåò êîìáèíàöèþ êàðò
int  combination(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int *nominal, unsigned int *kk1, unsigned int *kk2)
{
     void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);//ôóíêöèÿ îáìåíèâàþùàÿ êàðòû â ÿ÷åéêàõ, íà êîòîðûå ïîêàçûâàþò óêàçàòåëè

     unsigned int counter[FACES]={0};//ñêîëüêî îäèíàêîâûõ íîìèíàëîâ êàðò íà ðóêàõ ó èãðîêà
     unsigned int counter1[SUITS]={0};//ñêîëüêî îäèíàêîâûõ ìàñòåé êàðò íà ðóêàõ ó èãðîêà

     unsigned int wSortPlayer[5][2] = {0};

     

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
				 *kk1 = p;//çàïîìèíàåì íîìèíàë ïåðâîé ïàðû
			 }
			 else if(t == 2)//åñëè íà ðóêàõ äâå ïàðû
			 {
				 *kk2 = p;//çàïîìèíàåì íîìèíàë âòîðîé ïàðû
			 }
         }
		// ---------------------------3--ÒÐÈ_ÊÀÐÒû----------------------------
         else if(counter[p] == 3 )//åñëè íà ðóêàõ òðè îäèíàêîâûå êàðòû
         {
             *kk1 = p;
			 t = 3;//ïðèîðèòåò êîìáèíàöèè
         }
		 // ---------------------------6--×ÅÒÛÐÅ_ÊÀÐÒÛ----------------------------
         else if(counter[p] == 4 )//åñëè íà ðóêàõ ÷åòûðå îäèíàêîâûå êàðòû
         {
			*kk1 = p;
            t = 6;//ïðèîðèòåò êîìáèíàöèè
         }
     }

     // ---------------------------5(FLASH)------------------------------

     for( size_t p = 0; p < SUITS; ++p)
     {  
		 if(counter1[p] == 5 )//åñëè ïÿòü êàðò îäíîé ìàñòè
         {
		    t = 5;//ïðèîðèòåò êîìáèíàöèè
		 }
	     // ---------------------------7(FLASH_DRO)------------------------------
         else if(counter1[p] == 4 )
			{
                *kk1 = p;
                t = 7;//ïðèîðèòåò êîìáèíàöèè
			}
	}
    if(t == 5)
	{
		 for (size_t i = 0; i < 5; ++i )
         {
			 *nominal += wPlayer[i][1];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè
         }
	}
	//-----------------------------------------------------------------------------

    //ñîðòèðîâêà ìàññèâà êàðò, êîòîðûå èìåþòñÿ íà ðóêàõ ó èãðîêà
    for( size_t i = 0; i < 4; ++i)
    {
		 for( size_t j = 0; j < 4; ++j)
         {	
			if(wPlayer[j][1] > wPlayer[j + 1][1])
			 {
				 swap(&wPlayer[j][1], &wPlayer[j + 1][1]);//îáìåí ýëåìåíòîâ
				 swap(&wPlayer[j][0], &wPlayer[j + 1][0]);
			 }			
	     }
    }
    // ---------------------------4(STRAIGHT)------------------------------
    //îïðåäåëèòü, èäóò ëè êàðòû ïî ïîðÿäêó, íî ìàñòè ðàçíûå
     	    
       if(wPlayer[4][1]-1 == wPlayer[3][1] && wPlayer[3][1] - 1 == wPlayer[2][1] && wPlayer[2][1] - 1 == wPlayer[1][1] && wPlayer[1][1] - 1 == wPlayer[0][1])
	   {
		   for (size_t i = 0; i < 5; ++i )
		   {
			   *nominal += wPlayer[i][1];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè
		   }
		   t = 4;
	   }
	   // ---------------------------8(STRAIGHT_DRO)------------------------------
	   else if(wPlayer[4][1] - 1 == wPlayer[3][1] && wPlayer[3][1] - 1 == wPlayer[2][1] && wPlayer[2][1] - 1 == wPlayer[1][1] || wPlayer[3][1] - 1 == wPlayer[2][1] && wPlayer[2][1] - 1 == wPlayer[1][1] && wPlayer[1][1] - 1 == wPlayer[0][1])
		 {
 // ---------------------------9(COMBO_DRO)------------------------------
		   if(t == 0 || t == 1)
			 {
		        t = 8;
			 }
			  else if(t == 7)
			 {
			   t = 9;
			 }
			
		 }
     // --------------------------1----------------------------
     if(t == 1)//åñëè íà ðóêàõ îäíà ïàðà
     {
		*nominal = *kk1;//çàïîìíèòü íîìèíàë ïåðâîé ïàðû	
	 }
	 // ---------------------------2------------------------------
     else if(t == 2)//åñëè íà ðóêàõ äâå ïàðû
     {
		 *nominal = *kk1 + *kk2;//ñ÷èòàåì ñóììó íîìèíàëîâ äâóõ ïàð
     } 
      return t;
}

void printCombination(unsigned int tt)
{
	if(tt == 0)
	{
        printf("NO COMBINATION!\n");
	}
	else if(tt == 1 || tt == 2)
	{
        printf("\nThe hand contains a  %u PAIR.\n", tt );
	}
	else if(tt == 3)
	{
        printf("\nThe hand contains a  THREE CARDS.\n");
	}
	else if(tt == 4)
	{
		printf("\nThe hand contains a STRAIGHT.\n");
	}
	else if(tt == 5)
	{
		printf("\nThe hand contains a FLASH.\n");
	}
	else if(tt == 6)
	{
        printf("\nThe hand contains a FOUR CARDS.\n");
	}
    else if(tt == 7)
	{
		printf("\nThe hand contains a FLASH DRO. \n" );
	}
	else if(tt == 8)
	{
		printf("The hand contains a STRAIGHT DRO.\n");
	}
	else if(tt == 9)
	{
		printf("The hand contains a COMBO DRO.\n");
	}
}

//ôóíêöèÿ îáìåíèâàþùàÿ êàðòû â ÿ÷åéêàõ, íà êîòîðûå ïîêàçûâàþò óêàçàòåëè
void swap(unsigned int * element1Ptr, unsigned int * element2Ptr)
{
	unsigned int temp = * element1Ptr;
    * element1Ptr = * element2Ptr;
    * element2Ptr = temp;
}

