#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUITS 4
#define FACES 13
#define CARDS 52

//прототипы
void shuffle(unsigned int wDeck[][FACES]); // тасовать колоду карт
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int *n1,  unsigned int *f1); // раздать карты, не изменяя массива
int combination(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *nominal, unsigned int *kk1, unsigned int *kk2);//определить комбинацию карт
void printArray(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int pd);//распечатать карты игрока
void printCombination(unsigned int tt);//печать комбинация карт
void takeCards(unsigned int wPlayer[][2], unsigned int *nominal, unsigned int tt, unsigned int *kk1, unsigned int *kk2, unsigned int *f1);//сколько еще взять карт


int main(void)
{
	  unsigned int deck[SUITS][FACES] = {0};

	 unsigned int player1[5][2]; //карты на руках у первого игрока
	 unsigned int player2[5][2]; //карты на руках у второго игрока
   
	 unsigned int combination1;//комбинация карт первого игрока
	 unsigned int combination2;//комбинация карт второго игрока

	 unsigned int nominal1 = 0;//сумма номиналов карт первого игрока
	 unsigned int nominal2 = 0;//сумма номиналов карт второго игрока

	 unsigned int start = 1;
	 unsigned int finish = 5;
    
	 unsigned int flag = 0;//счетчик при определении старшей карты, сколько карт оказались равны
	 unsigned int pl_dl = 0;//если дилер - 1, если игрок -0 

	 unsigned int k1 = 100;//переменная для запоминания номинала первой пары карт
	 unsigned int k2 = 100;//переменная для запоминания номинала второй пары карт
     
	 // инициализация массива мастей
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // инициализация массива номиналов(значений)
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
     
	 //засеять гениратор случайных чисел
	 srand(time(NULL)); 
	 //тасовать колоду карт
     shuffle(deck);

     //сдать карты первому игроку
     printf("\nHand1-------------------\n\n");
     deal(deck, player1, face, suit, &start, &finish); 
     printArray(player1, face, suit, 1); 

     //сдать карты второму игроку
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

//определить, сколько карт взять еще
void takeCards(unsigned int wPlayer[][2], unsigned int *nominal, unsigned int tt, unsigned int *kk1, unsigned int *kk2, unsigned int *f1)
{
	unsigned int wSortPlayer[5][2] = {0};//временный массив
	unsigned int x = 0;//счетчик для карт, которые будут обмениваться
	unsigned int m = 0;//счетчик карт, которые составляют комбинацию
	
    if( tt < 7 && tt > 3)//если выпало 4 одинаковые карты флеш, стрит
	{
		m = 0;//берем 0 карт
	}
	else if(tt == 0 || tt == 1)//если нет комбинаций или выпала одна пара
	{
		m = 3;//взять 3 карты
	}
	else if(tt == 3)//если выпало 3 карты
	{
		m = 2;//берем 2 карты
	}
	else//в остальных случаях
	{
		m = 1;//берем 1 карту
	} 
	*f1 = m;//запоминаем количество карт, которые будут взяты
    printf("\nTake %u cards!\n\n", m);

	if(tt > 7 && wPlayer[0][1] + 1 != wPlayer[1][1])//если стрит дро, комбо дро и первая карта не входит в комбинацию, то ничего не меняем
	{
		puts("");
	}
	else if(tt > 6 || tt < 4)//все варианты, кроме флеш, 4 карты, стрит
    {
       for( size_t i = 0; i < 5; ++i)
	   {
		     if(tt > 7 && i == 0 && wPlayer[0][1] + 1 == wPlayer[1][1])//если стрит дро, комбо дро и первая карта  входит в комбинацию, то последняя карта становится первой
	        {
			    wSortPlayer[0][1] = wPlayer[4][1];
			    wSortPlayer[0][0] = wPlayer[4][0];
			}
            else if( (tt == 7 && wPlayer[i][0] != *kk1) || (tt < 7 && wPlayer[i][1] != *kk1 && wPlayer[i][1] != *kk2) )//если флеш дро и элемент массива равен номиналу комбинации или комбинация меньше флеш дро и элемент массива не равен номиналу комбинации
		    {
				//карта отправляется в начало массива
			    wSortPlayer[x][1] = wPlayer[i][1];
				wSortPlayer[x][0] = wPlayer[i][0];
			    x++;
		    }
			else 
		    { 
				if(tt > 7 && m == 1 )//если стрит дро или комбо дро, то карту передвигаем на одну позицию вниз
				{
				    i = i - 1;
				}
				wSortPlayer[m][1] = wPlayer[i][1];
				wSortPlayer[m][0] = wPlayer[i][0];
				++m;
		    }
	   }
	   //перезависать из временного массива карты
	   for( size_t i = 0; i < 5; ++i)
	   {
	        wPlayer[i][1]=wSortPlayer[i][1];
	        wPlayer[i][0]=wSortPlayer[i][0];
	   }
	}
}

// перетасовать карты в колоде
void shuffle(unsigned int wDeck[][FACES])
{
    // для каждой из 52 карт случайно выбрать место в колоде
     for (size_t card = 1; card <= CARDS; ++card)
	 {
         size_t row; // номер строкт
         size_t column; // номер столбца

         // выбрать новую позицию, пока не будет найдена свободная
         do {
             row = rand() % SUITS;
             column = rand() % FACES;
         } while(wDeck[row][column] != 0); 

         // поместить номер карты в выбранное место колоды
         wDeck[row][column] = card;
     }
} 

// сдать карты
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[],  unsigned int *n1,  unsigned int *f1)
{
	 unsigned int r = 0;//счетчик определяющий номинал и масть карт
     *f1 += *n1;//определить конечную карту при раздаче

     // сдать карты в указанных пределах
     for (size_t card = *n1; card < *f1; ++card)
	 {
         // цикл по строкам
		 for (size_t row = 0; row < SUITS; ++row)
		 {
             // цикл по столбцам в текущей строке
             for (size_t column = 0; column < FACES; ++column)
		     {
				 if (wDeck[row][column] == card) 
				 {
					 wPlayer[r][0] = row;//запомнить масть карты, полученной игроком
					 wPlayer[r][1] = column;//запомнить номинал карты, полученной игроком
					 ++r; 
	            }   
            }
        }
	 }
	 *n1 = *f1;//определелить первую карту при следующей раздаче карт
}

//распечатать карты игрока
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

//определяет комбинацию карт
int  combination(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int *nominal, unsigned int *kk1, unsigned int *kk2)
{
     void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);//функция обменивающая карты в ячейках, на которые показывают указатели

     unsigned int counter[FACES]={0};//сколько одинаковых номиналов карт на руках у игрока
     unsigned int counter1[SUITS]={0};//сколько одинаковых мастей карт на руках у игрока

     unsigned int wSortPlayer[5][2] = {0};

     

     size_t t = 0;//приоритет комбинации
	
     
     for(unsigned int r = 0; r < 5; ++r)
     {
         ++counter[wPlayer[r][1]];//считаем, сколько одинаковых номиналов карт на руках у игрока
         ++counter1[wPlayer[r][0]];//считаем, сколько одинаковых мастей карт на руках у игрока
     }
     
     for( unsigned int p = 0; p < FACES; ++p)
     {
         if(counter[p] == 2 )//если две одинаковые карты
         {
             t++;//увеличиваем счетчик на единицу, так как на руках  пара карт
			 if(t == 1)//если на руках одна пара
			 {
				 *kk1 = p;//запоминаем номинал первой пары
			 }
			 else if(t == 2)//если на руках две пары
			 {
				 *kk2 = p;//запоминаем номинал второй пары
			 }
         }
		// ---------------------------3--ТРИ_КАРТы----------------------------
         else if(counter[p] == 3 )//если на руках три одинаковые карты
         {
             *kk1 = p;
			 t = 3;//приоритет комбинации
         }
		 // ---------------------------6--ЧЕТЫРЕ_КАРТЫ----------------------------
         else if(counter[p] == 4 )//если на руках четыре одинаковые карты
         {
			*kk1 = p;
            t = 6;//приоритет комбинации
         }
     }

     // ---------------------------5(FLASH)------------------------------

     for( size_t p = 0; p < SUITS; ++p)
     {  
		 if(counter1[p] == 5 )//если пять карт одной масти
         {
		    t = 5;//приоритет комбинации
		 }
	     // ---------------------------7(FLASH_DRO)------------------------------
         else if(counter1[p] == 4 )
			{
                *kk1 = p;
                t = 7;//приоритет комбинации
			}
	}
    if(t == 5)
	{
		 for (size_t i = 0; i < 5; ++i )
         {
			 *nominal += wPlayer[i][1];//вычисляем сумму номиналов карт одной масти
         }
	}
	//-----------------------------------------------------------------------------

    //сортировка массива карт, которые имеются на руках у игрока
    for( size_t i = 0; i < 4; ++i)
    {
		 for( size_t j = 0; j < 4; ++j)
         {	
			if(wPlayer[j][1] > wPlayer[j + 1][1])
			 {
				 swap(&wPlayer[j][1], &wPlayer[j + 1][1]);//обмен элементов
				 swap(&wPlayer[j][0], &wPlayer[j + 1][0]);
			 }			
	     }
    }
    // ---------------------------4(STRAIGHT)------------------------------
   //определить, идут ли карты по порядку, но масти разные
     	    
       if(wPlayer[4][1]-1 == wPlayer[3][1] && wPlayer[3][1] - 1 == wPlayer[2][1] && wPlayer[2][1] - 1 == wPlayer[1][1] && wPlayer[1][1] - 1 == wPlayer[0][1])
	   {
		   for (size_t i = 0; i < 5; ++i )
		   {
			   *nominal += wPlayer[i][1];//вычисляем сумму номиналов карт одной масти
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
     if(t == 1)//если на руках одна пара
     {
		*nominal = *kk1;//запомнить номинал первой пары	
	 }
	 // ---------------------------2------------------------------
     else if(t == 2)//если на руках две пары
     {
		 *nominal = *kk1 + *kk2;//считаем сумму номиналов двух пар
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

//функция обменивающая карты в ячейках, на которые показывают указатели
void swap(unsigned int * element1Ptr, unsigned int * element2Ptr)
{
	unsigned int temp = * element1Ptr;
    * element1Ptr = * element2Ptr;
    * element2Ptr = temp;
}

