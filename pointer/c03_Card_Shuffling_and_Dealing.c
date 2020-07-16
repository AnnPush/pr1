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
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *n1,  unsigned int *f1); // ðàçäàòü êàðòû, íå èçìåíÿÿ ìàññèâ

int main(void)
{
	 //1_ èíèöèàëèçàöèÿ êîëîäû êàðò íóëÿìè
	 //unsigned int deck[SUITS][FACES] = {0};

	 //2_ èíèöèàëèçàöèÿ êîëîäû êàðò_íåò êîìáèíàöèé_ó_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10,  3, 27, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46,  4, 48, 49,  7, 51, 52};
     
	 //3_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_1_ÏÀÐÀ_ó_ïåðâîãî_èãðîêà
       unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46,  4, 48, 49,  7, 51, 52};
     //ìàññèâ_ïî_ïîðÿäêó
	 //unsigned int deck[SUITS][FACES] = { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
	 
	 //4_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_2_ÏÀÐÛ_ó_ïåðâîãî_èãðîêà

	 //5_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_3_ÊÀÐÒÛ_ó_ïåðâîãî_èãðîêà

     //6_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_4_ÊÀÐÒÛ_ó_ïåðâîãî_èãðîêà

     //7_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÔËÅØ_ó_ïåðâîãî_èãðîêà

	 //8_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÑÒÐÈÒ_ó_ïåðâîãî_èãðîêà

     //9_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÔËÅØ_ÄÐÎ_ó_ïåðâîãî_èãðîêà

	 //10_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÑÐÈÒ_ÄÐÎ_ó_ïåðâîãî_èãðîêà

     //11_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÊÎÌÁÎ_ÄÐÎ_ó_ïåðâîãî_èãðîêà

     //12_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_1_ÏÀÐÀ_ó_äâóõ_èãðîêîâ

	 //13_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_2_ÏÀÐÛ_ó_äâóõ_èãðîêîâ

	 //14_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_3_ÊÀÐÒÛ_ó_äâóõ_èãðîêîâ

     //15_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_4_ÊÀÐÒÛ_ó_äâóõ_èãðîêîâ

     //16_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÔËÅØ_ó_äâóõ_èãðîêîâ

	 //17_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÑÒÐÈÒ_ó_äâóõ_èãðîêîâ

     //18_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÔËÅØ_ÄÐÎ_ó_ïåðâîãî_äâóõ_èãðîêîâ

	 //19_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÑÐÈÒ_ÄÐÎ_ó_ïåðâîãî_äâóõ_èãðîêîâ

     //20_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÊÎÌÁÎ_ÄÐÎ_ó_ïåðâîãî_äâóõ_èãðîêîâ

     //21_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÔËÅØ_ó_ïåðâîãî_èãðîêà_4_ÊÀÐÒÛ_ó_âòîðîãî_èãðîêà

     //22_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÑÒÐÈÒ_ó_ïåðâîãî_èãðîêà_3_ÊÀÐÒÛ_ó_âòîðîãî_èãðîêà


    // unsigned int deck[SUITS][FACES] = { 1, 28,  27, 31, 32,  33, 22,  19, 14,  17, 24, 21, 20, 26, 6, 4, 7, 10, 30, 8, 12, 9, 29,  15, 11,  13,  16, 18,   3,  23, 25, 34, 35, 36, 37, 38, 39, 40, 41,  5, 2, 42,  43, 44,  45, 46, 47, 48, 49, 50, 51,  52 };
     // 1_para unsigned int deck[SUITS][FACES] = { 28,  27, 31, 32,  33, 22, 1, 19, 14,  17, 24, 21, 20, 26, 6, 4, 7, 10, 30, 8, 12, 9, 29,  15, 11,  13,  16, 18,   3,  23, 25, 34, 35, 36, 37, 38, 39, 40, 41,  42,2, 43, 44, 45, 46, 47, 48, 49, 50, 51, 5, 52 };
     //FLash_DRO  unsigned int deck[SUITS][FACES] = { 28,  27, 31, 32,  33, 22, 19, 14,  17, 24, 21, 20, 26, 6, 7, 10, 30, 8, 12, 9, 29,  15, 11,  13,  16, 18, 2, 1, 3, 4, 23, 25, 34, 35, 36, 37, 38, 39, 40, 41,  42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 5, 52 };
     
	 unsigned int player1[5][2]; //êàðòû íà ðóêàõ ó ïåðâîãî èãðîêà
	 unsigned int player2[5][2]; //êàðòû íà ðóêàõ ó âòîðîãî èãðîêà
   
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

printf("\nHand2\n\n");

finish = 5;
	 //ñäàòü êàðòû âòîðîìó èãðîêó ñ 5 ïî 9
	 deal(deck, player2, face, suit, &start, &finish);


 combination1 = rating(player1, face, suit, &nominal1);

  


	 if(combination1 > 3 && combination1 < 7)
	{
		 puts("\nNo cards!");
	}
   if(combination1 == 1 || combination1 == 0)
	{
           puts("\n3 cards!");
finish = 3;
	}
	else if(combination1 == 3)
	{
		 puts("\n2 cards!");
		 finish = 2;
	}
	else if(combination1 == 2 || combination1 == 7 || combination1 == 8 || combination1 == 9)
	{
        puts("\n1 card!");
		finish = 1;
	}



	 deal(deck, player1, face, suit, &start, &finish); 
	 printf("\nHand1\n\n");
/*for (size_t i = 0; i < 5; ++i)
{
	
     printf("%u of %u\n", player1[i][1], player1[i][0]);
printf("%5s of %-8s\n", face[player1[i][1]], suit[player1[i][0]]);
}*/
combination1 = rating(player1, face, suit, &nominal1);


printf("\nHand2\n\n");
 
	  //combination2 = rating(player2, face, suit, &nominal2);



	 if(combination1 > 6)
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
				 if(!printRating(&player1[i][1], &player2[i][1]))//åñëè íîìèíàëû ðàâíû, ñðàâíåíèå èäåò ïî ñîðòèðîâàííîìó ìàññèâó ïî ñòàðøåé êàðòå
		         {
					 flag++;
				 }
				 if( flag == 5)
				 {
                     printf("\nHand1 = Hand2\n");//êàðòû èãðîêîâ ðàâíû
			     }
			 }
		}
	}  
}




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
     unsigned int wSortPlayer[5][2] = {0};
     unsigned int k1 = 0;//ïåðåìåííàÿ äëÿ çàïîìèíàíèÿ íîìèíàëà ïåðâîé ïàðû êàðò
	 unsigned int k2 = 0;//ïåðåìåííàÿ äëÿ çàïîìèíàíèÿ íîìèíàëà âòîðîé ïàðû êàðò
unsigned int k3 = 0;
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
			 k3 = p;
			 t = 3;//ïðèîðèòåò êîìáèíàöèè
         }
		 // ---------------------------6------------------------------
         else if(counter[p] == 4 )//åñëè íà ðóêàõ ÷åòûðå îäèíàêîâûå êàðòû
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
// unsigned int b =0;
     //ñîðòèðîâêà ìàññèâà êàðò, êîòîðûå èìåþòñÿ íà ðóêàõ ó èãðîêà
    for( size_t i = 0; i < 4; ++i)
     {
		 for( size_t j = 0; j < 4; ++j)
         {	
			if(wPlayer[j][1] < wPlayer[j + 1][1])
			 {
				 swap(&wPlayer[j][1], &wPlayer[j + 1][1]);//îáìåí ýëåìåíòîâ
				 swap(&wPlayer[j][0], &wPlayer[j + 1][0]);
			 }			
	     }
	 }

	
 printf("\nSort1:\n ");
	 for( size_t i = 0; i < 5; ++i)
     {		
		  printf("%5s of %-8s\n ", wFace[ wPlayer[i][1]],  wSuit[ wPlayer[i][0]] );
	 }
 printf("\n ");

 unsigned int x = 0;
	    unsigned int m = 0;

    if( t < 7 && t > 4)
	{
		m = 0;
	}
	else if(t == 0 || t == 1)
	{
		m = 3;
	}
	else if(t == 3)
	{
		m = 2;
	}
	else
	{
		m = 1;
	}

	printf("Take %u cards!", m);
        

        for( size_t i = 0; i < 5; ++i)
		{

            /*if(m == 8 && wPlayer[i][0] != *nominal)
			{*/
            if( wPlayer[i][1] != *nominal )
			{
				wSortPlayer[x][1] = wPlayer[i][1];
				x++;
			}
			else
			{
				wSortPlayer[m][1] = wPlayer[i][1];
				++m;
			}
		}
		
	/* unsigned int b = 0;
	 unsigned int m = 0;
    if( t == 1)
	{
	    for( size_t i = 0; i < 5; ++i)
		{
		  if( wPlayer[i][1] == k1)
			{
			  
			  if(b == 1)
				 {
					 wSortPlayer[3][1] = wPlayer[i][1];
					 wSortPlayer[3][0] = wPlayer[i][0];
				 }
				 else
				{wSortPlayer[4][1] = wPlayer[i][1];
			  wSortPlayer[4][0] = wPlayer[i][0];
				}
				 b = 1;
			}
			else
			{
               wSortPlayer[m][1] = wPlayer[i][1];
			   wSortPlayer[m][0] = wPlayer[i][0];
			   ++m;
			}
		}
for( size_t i = 0; i < 5; ++i)
		{
	wPlayer[i][1]=wSortPlayer[i][1];
	wPlayer[i][0]=wSortPlayer[i][0];
		}
 

	}
	if( t == 2)
	{ m = 1;
	    for( size_t i = 0; i < 5; ++i)
		{
		  if( wPlayer[i][1] != k1 && wPlayer[i][1] != k2)
			{
			  wSortPlayer[0][1] = wPlayer[i][1];
					 wSortPlayer[0][0] = wPlayer[i][0];

					  
                       //printf("%5s of %-8s\n", wFace[wPlayer[i][1]], wSuit[wPlayer[i][0]]);
			}
			else
			{
				wSortPlayer[m][1] = wPlayer[i][1];
			   wSortPlayer[m][0] = wPlayer[i][0];
			   //printf("%u of %u, %d\n", wSortPlayer[m][1], wSortPlayer[m][0], m);
			   ++m;
			}
		}
		for( size_t i = 0; i < 5; ++i)
		{
	wPlayer[i][1]=wSortPlayer[i][1];
	wPlayer[i][0]=wSortPlayer[i][0];
		}
	}*/


	   printf("\nSort2:\n ");
	 for( size_t i = 0; i < 5; ++i)
     {	
		 
		  printf("%5s of %-8s\n ", wFace[ wPlayer[i][1]],  wSuit[ wPlayer[i][0]] );
	 }  /*if (t == 1 && wPlayer[i][1] == k1)
			 {
                 wSortPlayer[4][1] = wPlayer[i][1];
				 if(b == 1)
				 {
					 wSortPlayer[3][1] = wPlayer[i][1];
				 }
				 b = 1;
                 
			 }
			 else 
	{
				 wSortPlayer[i][1] = wPlayer[i][1];
	}

for( size_t i = 0; i < 0; ++i)
         {
wPlayer[i][1] = wSortPlayer[i][1];
		 }*/

     //òåñòèðîâàíèå ïðîãðàììû
	
// ---------------------------4(STRAIGHT)------------------------------
     //îïðåäåëèòü, èäóò ëè êàðòû ïî ïîðÿäêó, íî ìàñòè ðàçíûå
     	    
       if(wPlayer[4][1]-1 == wPlayer[3][1] && wPlayer[3][1] - 1 == wPlayer[2][1] && wPlayer[2][1] - 1 == wPlayer[1][1] && wPlayer[1][1] - 1 == wPlayer[9][1])
	   {
		   printf("\nThe hand contains a straight from %s to %s .\n", wFace[wPlayer[0][1]], wFace[wPlayer[4][1]]);
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
