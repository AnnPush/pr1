#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//ïðîòîòèïû

int rating(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *nominal, unsigned int *wSortPlayer);//îöåíêà êàðò
int printRating(unsigned int*, unsigned int*);//ïå÷àòü ðåçóëüòàòà îöåíèâàíèÿ êàðò

int main(void)
{
	 // èíèöèàëèçàöèÿ êîëîäû êàðò íóëÿìè
     unsigned int deck[SUITS][FACES] = {0};
     
	 unsigned int player1[5][2] = {{1, 2}, {0, 2}, {4, 2}, {5, 2}, {6, 2}};//êàðòû íà ðóêàõ ó ïåðâîãî èãðîêà
	 unsigned int player2[5][2]= {{8, 1}, {5, 1}, {0, 1}, {3, 1}, {10, 1}};//êàðòû íà ðóêàõ ó âòîðîãî èãðîêà
     

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

	 

	 // èíèöèàëèçàöèÿ ìàññèâà ìàñòåé
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // èíèöèàëèçàöèÿ ìàññèâà íîìèíàëîâ(çíà÷åíèé)
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

     printf("\nHand1\n\n");

	 printf("%5s of %-8s\n", face[1], suit[2]);
	 printf("%5s of %-8s\n", face[0], suit[2]);
	 printf("%5s of %-8s\n", face[4], suit[2]);
	 printf("%5s of %-8s\n", face[5], suit[2]);
	 printf("%5s of %-8s\n", face[6], suit[2]);
	 
	 
	 printf("\nHand2\n\n");

     
     printf("%5s of %-8s\n", face[8], suit[1]);
	 printf("%5s of %-8s\n", face[5], suit[1]);
	 printf("%5s of %-8s\n", face[0], suit[1]);
	 printf("%5s of %-8s\n", face[3], suit[1]);
	 printf("%5s of %-8s\n", face[10], suit[1]);
     
	 //íàéòè êîìáèíàöèþ êàðò ïåðâîãî èãðîêà
	 combination1 = rating(player1, face, suit, &nominal1, sortPlayer1);
    
	 //íàéòè êîìáèíàöèþ êàðò âòîðîãî èãðîêà
	 combination2 = rating(player2, face, suit, &nominal2, sortPlayer2);

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
	}  
}



//îöåíêà êàðò
int  rating(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int *nominal, unsigned int *wSortPlayer)
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
		 printf("\nwPlayer[%d][1] %d\n", r, wPlayer[r][1]);
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
         }
         else if(counter[p] == 4 )//ååñëè íà ðóêàõ ÷åòûðå îäèíàêîâûå êàðòû
         {
             printf("\nThe hand contains a four %s\n", wFace[p] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
			 t = 6;//ïðèîðèòåò êîìáèíàöèè
         }
     }
     
     if(t == 1)//åñëè íà ðóêàõ îäíà ïàðà
     {
        printf("\nThe hand contains a pair %s\n", wFace[k1] );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
		*nominal = k1;//çàïîìíèòü íîìèíàë ïåðâîé ïàðû
		
		
	 }
     else if(t == 2)//åñëè íà ðóêàõ äâå ïàðû
     {
         printf("\nThe hand contains a two pairs %s and  %s\n", wFace[k1],wFace[k2]  );//âûâîäèì ñîîáùåíèå è íîìèíàë êàðòû íà ýêðàí
		 *nominal = k1 + k2;//ñ÷èòàåì ñóììó íîìèíàëîâ äâóõ ïàð
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
		    }
	    }
		for (size_t i = 0; i < 5; ++i )
		{
			*nominal += wSortPlayer[i];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè
		}
       // printf("\nNominal_flash %d\n", *nominal );
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


     //îïðåäåëèòü, èäóò ëè êàðòû ïî ïîðÿäêó, íî ìàñòè ðàçíûå
     if( t == 0)
	 {	    
       if(wSortPlayer[4]-1 == wSortPlayer[3] && wSortPlayer[3]-1 == wSortPlayer[2] && wSortPlayer[2]-1 == wSortPlayer[1] && wSortPlayer[1]-1 == wSortPlayer[0])
	   {
		   printf("The hand contains a straight from %s to %s/ \n", wFace[wSortPlayer[0]], wFace[wSortPlayer[4]]);
		   for (size_t i = 0; i < 5; ++i )
		   {
			   *nominal += wSortPlayer[i];//âû÷èñëÿåì ñóììó íîìèíàëîâ êàðò îäíîé ìàñòè
		   }
		   t = 4;
	   }
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
