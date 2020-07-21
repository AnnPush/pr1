#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//ïðîòîòèïû
void shuffle(unsigned int wDeck[][FACES]); // òàñîâàòü êîëîäó êàðò
int printRating(unsigned int*, unsigned int*);//ïå÷àòü ðåçóëüòàòà îöåíèâàíèÿ êàðò
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *n1,  unsigned int *f1); // ðàçäàòü êàðòû, íå èçìåíÿÿ ìàññèâ
int combination(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *nominal, unsigned int *kk1, unsigned int *kk2, unsigned int *com);
void printArray(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int pd);
void printCombination(unsigned int tt);
void takeCards(unsigned int wPlayer[][2], unsigned int *nominal, unsigned int tt, unsigned int *kk1, unsigned int *kk2, unsigned int *f1);


int main(void)
{
	 //1_ èíèöèàëèçàöèÿ êîëîäû êàðò íóëÿìè(ïðè òåñòèðîâàíèè çàêîììåíòèðîâàòü ýòó ñòðîêó è âûáðàòü îäíó èç ïîñëåäóþùèõ)
	 unsigned int deck[SUITS][FACES] = {0};

	 //2_ èíèöèàëèçàöèÿ êîëîäû êàðò_íåò êîìáèíàöèé_ó_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {28,  2, 13, 31, 32, 33,  8, 21,  4, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47, 5, 29, 15, 10,  1, 27, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46,  3,  48, 49,  7, 51, 52};
     //ìàññèâ_ïî_ïîðÿäêó
	 //unsigned int deck[SUITS][FACES] = { 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52};
	 
	 //3_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_1_ÏÀÐÀ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46,  4, 48, 49,  7, 51, 52};
     
	 //4_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_2_ÏÀÐÛ_ó_ïåðâîãî_èãðîêà
	 //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 14, 42, 43, 44, 45, 46, 49, 48,  4,  7, 51, 52};
     
	 //5_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_3_ÊÀÐÒÛ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41,  4, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
    
     //6_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_4_ÊÀÐÒÛ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21, 37, 17, 19, 11, 20, 26,  5,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41,  4, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
     //7_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÔËÅØ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31,  2, 33,  3, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 28, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
	 //8_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÑÒÐÈÒ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31,  5, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  9,  3, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23,  4, 34, 35, 36,  6, 38, 39, 40, 41, 28,  2, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
     //9_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÔËÅØ_ÄÐÎ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31, 48, 33,  3, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23, 25, 34, 35, 36,  6, 38, 39, 40, 41, 28, 42, 43, 44, 45, 46, 49,  2, 14,  7, 51, 52};
     
	 //10_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÑÒÐÈÒ_ÄÐÎ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = {25, 38, 13, 31,  5, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  9,  3, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23,  4, 34, 35, 36,  6,  1, 39, 40, 41, 28,  2, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
     
     //11_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÊÎÌÁÎ_ÄÐÎ_ó_ïåðâîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31, 48, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  9, 14, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27,  8, 16, 18, 23, 46, 34, 35, 36,  6, 38, 39, 40, 41, 28, 49, 43, 44, 45,  4,  2,  5,  3,  7, 51, 52};
     
	 //12_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_1_ÏÀÐÀ_ó_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11, 20, 26, 37,  9, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36, 40, 38, 39,  6, 41, 14, 42, 43, 44, 45, 46,  4, 48, 49,  7, 51, 52};
    
	 //13_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_2_ÏÀÐÛ_ó_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17,  9, 11, 20, 26, 37, 49, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36, 40, 38, 39,  6, 41, 14, 42, 43, 44, 45, 46, 19, 48,  4,  7, 51, 52};
    
	 //14_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_3_ÊÀÐÒÛ_ó_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {28,  1, 13, 31, 32, 33,  8, 21,  5, 17, 19, 11,  9, 26, 37, 20, 50, 12, 30, 22, 24, 47,  2, 29, 15, 10, 27,  3, 16, 18, 23, 25, 34, 35, 36, 40, 38, 39,  6, 41,  4, 42, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
    
     //15_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_4_ÊÀÐÒÛ_ó_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = { 6,  1, 13, 31, 32, 33, 41, 21, 37, 17, 19, 11, 20,  7,  5, 28, 50, 12, 30, 22, 24, 47,  2, 29, 15, 27, 10,  3, 16, 18, 23, 25, 34, 35, 36,  9, 38, 39, 40,  8,  4, 42, 43, 44, 45, 46, 49, 48, 14, 26, 51, 52};
     
     //16_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÔËÅØ_ó_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31,  2, 33,  3, 21,  5, 17, 19, 11, 20, 26,  8, 16, 50, 12,  6, 22, 24, 10, 32,  7, 15,  9, 27, 37, 47, 18, 23, 25, 34, 35, 36, 30, 38, 39, 40, 41, 28, 42, 43, 44, 45, 46, 49, 48, 14, 29, 51, 52};
     
	 //17_ èíèöèàëèçàöèÿ êîëîäû êàðò_êîìáèíàöèÿ_ÑÒÐÈÒ_ó_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 10,  5, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  8,  3, 12, 30, 22, 24, 47, 32, 29, 15, 31,  6, 28, 16, 18, 23,  4, 34, 35, 36, 27, 38, 39, 40, 41,  9,  2, 43,  7, 45, 46, 49, 48, 14, 44, 51, 52};
    
     //18_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÔËÅØ_ÄÐÎ_ó_ïåðâîãî_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = { 4,  1, 13, 31, 48, 33,  3, 21,  5, 17, 19, 37, 20, 26,  8, 16, 50, 12, 30, 22, 24, 10, 32,  7, 15,  9, 27, 11, 47, 18, 23, 25, 34, 35, 36, 44, 38, 39, 40, 41, 28, 42, 43,  6, 45, 46, 49,  2, 14, 29, 51, 52};
     
	 //19_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÑÐÈÒ_ÄÐÎ_ó_ïåðâîãî_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {25, 38, 13, 10,  4, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37,  8,  3, 12, 52, 22, 24, 47, 32, 29, 15, 31,  6, 28, 16, 18, 23, 5, 34, 35, 36, 27,  1, 39, 40, 41,  9,  2, 43, 44, 45, 46, 49, 48, 14, 30, 51,  7};
      
     //20_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÊÎÌÁÎ_ÄÐÎ_ó_ïåðâîãî_äâóõ_èãðîêîâ
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31, 48, 33, 50, 21, 42, 17, 19, 11, 20, 26, 37, 47, 14, 12,  7,  6,  8,  9, 32, 29, 15, 27, 10, 24, 16, 18, 23, 46, 34, 35, 36, 22, 38, 39, 40, 41, 28, 49, 43, 44, 45,  4,  2,  5,  3, 30, 51, 52};
     
     //21_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÔËÅØ_ó_ïåðâîãî_èãðîêà_4_ÊÀÐÒÛ_ó_âòîðîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = { 6,  1, 13, 31,  2, 33,  3, 21,  5, 17, 19, 11,  4,  7, 37, 20, 50, 12, 30, 22, 24, 47, 32, 29, 15, 27, 10, 41, 16, 18, 23, 25, 34, 35, 36,  9, 38, 39, 40,  8, 28, 42, 43, 44, 45, 46, 49, 48, 14, 26, 51, 52};
      
     //22_ èíèöèàëèçàöèÿ êîëîäû êàðò_ÑÒÐÈÒ_ó_ïåðâîãî_èãðîêà_3_ÊÀÐÒÛ_ó_âòîðîãî_èãðîêà
     //unsigned int deck[SUITS][FACES] = {25,  1, 13, 31,  5, 33,  8, 21, 42, 17, 19, 11,  9, 26, 37, 20,  3, 12, 30, 22, 24, 47, 32, 29, 15, 10, 27, 50, 16, 18, 23,  4, 34, 35, 36, 40, 38, 39,  6, 41, 28,  2, 43, 44, 45, 46, 49, 48, 14,  7, 51, 52};
      
	 unsigned int player1[5][2]; //êàðòû íà ðóêàõ ó ïåðâîãî èãðîêà
	 unsigned int player2[5][2]; //êàðòû íà ðóêàõ ó âòîðîãî èãðîêà
   
	 unsigned int combination1;//êîìáèíàöèÿ êàðò ïåðâîãî èãðîêà
	 unsigned int combination2;//êîìáèíàöèÿ êàðò âòîðîãî èãðîêà

	 unsigned int nominal1 = 100;//ñóììà íîìèíàëîâ êàðò ïåðâîãî èãðîêà
	 unsigned int nominal2 = 100;//ñóììà íîìèíàëîâ êàðò âòîðîãî èãðîêà

     unsigned int combo1 = 0;
	 unsigned int combo2 = 0;

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
	 //òàñîâàòü êîëîäó êàðò(ïðè òåñòèðîâàíèè çàêîììåíòèðîâàòü ýòó ñòðîêó)
     shuffle(deck);

     //ñäàòü êàðòû ïåðâîìó èãðîêó
     printf("\nHand1-------------------\n\n");
     deal(deck, player1, face, suit, &start, &finish); 
     printArray(player1, face, suit, 0); 

     //ñäàòü êàðòû âòîðîìó èãðîêó
     printf("\nHand2-------------------\n\n");
     finish = 5;
	 deal(deck, player2, face, suit, &start, &finish);
     printArray(player2, face, suit, 0);

	 printf("\nHand1-------------------\n");
	 combination1 = combination(player1, face, suit, &nominal1, &k1, &k2, &combo1);
	 printArray(player1, face, suit, 0);
	 printCombination(combination1);
	 takeCards(player1, &nominal1, combination1, &k1, &k2, &finish);
	  printf("\nTake %u cards!\n\n", finish);
     printArray(player1, face, suit, 0);
	 if(finish != 0)
	 {
		 deal(deck, player1, face, suit, &start, &finish); 
		 printf("\nNew_array\n");
		 printArray(player1, face, suit, 0);
	 }
	 combination1 = combination(player1, face, suit, &nominal1, &k1, &k2, &combo1);
	 printArray(player1, face, suit, 0);
	 printCombination(combination1);

	 printf("\nHand2-------------------\n\n");
	 combination2 = combination(player2, face, suit, &nominal2, &k1, &k2, &combo2);
	 printArray(player2, face, suit, 0);
	 printCombination(combination2);

     takeCards(player2, &nominal1, combination1, &k1, &k2, &finish);
     printArray(player2, face, suit, 0);
	 
	 printf("\nHow many cards do you want to take?\n\n");
	 scanf("%u", &finish);
	 	 if(finish != 0)
	 {
		 deal(deck, player2, face, suit, &start, &finish); 
		 printf("\nNew_array\n");
		 printArray(player2, face, suit, 0);
	 }
	 combination2 = combination(player2, face, suit, &nominal2, &k1, &k2, &combo2);
	 printArray(player2, face, suit, 0);
	 printCombination(combination2);
	 

	 if(!printRating(&combo1, &combo2))//ñðàâíèòü êîìáèíàöèè êàðò
	 {
		 if(!printRating(&nominal1, &nominal2))//åñëè êîìáèíàöèè ðàâíû, ñðàâíèòü íîìèíàëû
		 {
			 for(size_t i = 4 ; i >= 0; --i)
			 {
				 if(!printRating(&player1[i][1], &player2[i][1]))//åñëè íîìèíàëû ðàâíû, ñðàâíåíèå èäåò ïî ñîðòèðîâàííîìó ìàññèâó ïî ñòàðøåé êàðòå
		         {
					 flag++;
				 }
				 else
				 {
					 break;
				 }
				 
			 }
			 if( flag == 5)
			 {
                  printf("\nHand1 = Hand2\n");//êàðòû èãðîêîâ ðàâíû
			 }
		}
	}  
	 
}

void takeCards(unsigned int wPlayer[][2], unsigned int *nominal, unsigned int tt, unsigned int *kk1, unsigned int *kk2, unsigned int *f1)
{
	unsigned int wSortPlayer[5][2] = {0};
	unsigned int x = 0;
	unsigned int m = 0;
	
    if( tt < 7 && tt > 3)
	{
		m = 0;
	}
	else if(tt == 0 || tt == 1)
	{
		m = 3;
	}
	else if(tt == 3)
	{
		m = 2;
	}
	else
	{
		m = 1;
	} 
	*f1 = m;
   

	if(tt > 6 || tt < 4)
    {
       for( size_t i = 0; i < 5; ++i)
	   {
		     if(tt > 7 && i == 0 && wPlayer[0][1] + 1 == wPlayer[1][1])
	        {
			    wSortPlayer[0][1] = wPlayer[4][1];
			    wSortPlayer[0][0] = wPlayer[4][0];
			}
            else if( (tt == 7 && wPlayer[i][0] != *kk1) || (tt < 7 && wPlayer[i][1] != *kk1 && wPlayer[i][1] != *kk2) )
		    {
			    wSortPlayer[x][1] = wPlayer[i][1];
				wSortPlayer[x][0] = wPlayer[i][0];
			    x++;
		    }
			else 
		    { 
				if(tt > 7 && m == 1 )
				{
				    i = i - 1;
				}
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
}

// ïåðåòàñîâàòü êàðòû â êîëîäå(ïðè òåñòèðîâàíèè çàêîììåíòèðîâàòü ýòó ôóíêöèþ)
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
int  combination(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int *nominal, unsigned int *kk1, unsigned int *kk2, unsigned int *com)
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
			 *com = 3;
         }
		 // ---------------------------6--×ÅÒÛÐÅ_ÊÀÐÒÛ----------------------------
         else if(counter[p] == 4 )//åñëè íà ðóêàõ ÷åòûðå îäèíàêîâûå êàðòû
         {
			*kk1 = p;
            t = 6;//ïðèîðèòåò êîìáèíàöèè
			*com = 6;
         }
     }

     // ---------------------------5(FLASH)------------------------------

     for( size_t p = 0; p < SUITS; ++p)
     {  
		 if(counter1[p] == 5 )//åñëè ïÿòü êàðò îäíîé ìàñòè
         {
		    t = 5;//ïðèîðèòåò êîìáèíàöèè
			*com = 5;
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
		   *com = 4;
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
		*com = 1;
	 }
	 // ---------------------------2------------------------------
     else if(t == 2)//åñëè íà ðóêàõ äâå ïàðû
     {
		 *nominal = *kk1 + *kk2;//ñ÷èòàåì ñóììó íîìèíàëîâ äâóõ ïàð
		 *com = 2;
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
