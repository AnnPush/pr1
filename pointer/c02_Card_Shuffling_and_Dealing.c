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

//прототипы
void shuffle(unsigned int wDeck[][FACES]); // тасовать колоду карт
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2],  const char *wFace[], const char *wSuit[], unsigned int n1,  unsigned int f1); // раздать карты не изменяя массив
int rating(unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[], unsigned int *nominal, unsigned int *wSortPlayer);//оценка карт
int printRating(unsigned int*, unsigned int*);//печать результата оценивания карт

int main(void)
{
	 // инициализация колоды карт нулями
     unsigned int deck[SUITS][FACES] = {0};
     
	 unsigned int player1[5][2];//карты на руках у первого игрока
	 unsigned int player2[5][2];//карты на руках у второго игрока

     unsigned int sortPlayer1[5];//сортированный массив карт на руках у первого игрока
	 unsigned int sortPlayer2[5];//сортированный массив карт на руках у второго игрока

	 unsigned int combination1;//комбинация карт первого игрока
	 unsigned int combination2;//комбинация карт второго игрока

	 unsigned int nominal1 = 0;//сумма номиналов карт первого игрока
	 unsigned int nominal2 = 0;//сумма номиналов карт второго игрока

	 unsigned int flag = 0;//счетчик при определении старшей карты, сколько карт оказались равны

	 //засеять генератор случайных чисел 
	 srand(time(NULL)); 
     shuffle(deck); // тасовать колоду

	 // инициализация массива мастей
     const char *suit[SUITS] = {"Hearts", "Diamonds", "Clubs", "Spades"};

	 // инициализация массива номиналов(значений)
     const char *face[FACES] = {"Ace", "Deuce", "Three", "Four",
                                "Five", "Six", "Seven", "Eight",
                                "Nine", "Ten", "Jack", "Queen", "King"};

     printf("\nHand1\n\n");

	 //сдать карты первому игроку с 0 по 4
	 deal(deck, player1, face, suit, 1, 5); 
	 //найти комбинацию карт первого игрока
	 combination1 = rating(player1, face, suit, &nominal1, sortPlayer1);


     printf("\nHand2\n\n");

	 //сдать карты второму игроку с 5 по 9
	 deal(deck, player2, face, suit, 5, 9); 
	 //найти комбинацию карт второго игрока
	 combination2 = rating(player2, face, suit, &nominal2, sortPlayer2);

	 //печать результата оценивания карт
	 if(!printRating(&combination1, &combination2))//сравнить комбинации карт
	 {
		 if(!printRating(&nominal1, &nominal2))//если комбинации равны, сравнить номиналы
		 {
			 for(size_t i =0 ; i < 5; ++i)
			 {
				 if(!printRating(&sortPlayer1[i], &sortPlayer2[i]))//если номиналы равны, сравнение идет по сортированному массиву по старшей карте
		         {
					 flag++;
				 }
				 if( flag == 5)
				 {
                     printf("\nHand1 = Hand2\n");//карты игроков равны
			     }
			 }
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
void deal(unsigned int wDeck[][FACES], unsigned int wPlayer[][2], const char *wFace[], const char *wSuit[],  unsigned int n1,  unsigned int f1)
{
	 unsigned int r = 0;//счетчик определяющий номинал и масть карт

     // сдать карты в указанных пределах
     for (size_t card = n1; card <= f1; ++card)
	 {
         // цикл по строкам
         for (size_t row = 0; row < SUITS; ++row)
		 {
             // цикл по столбцам в текущей строке
             for (size_t column = 0; column < FACES; ++column)
		     {
                 // если ячейка содержит текущую карту, вывести ее
                 if (wDeck[row][column] == card) 
				 {
					 wPlayer[r][0] = row;//запомнить масть карты, полученной игроком
					 wPlayer[r][1] = column;//запомнить номинал карты, полученной игроком
	                 printf("%5s of %-8s\n", wFace[column], wSuit[row]);//печать карты, полученной игроком 
					 ++r;
                 }
             }
         }
     }
}

//оценка карт
int  rating(unsigned int wPlayer[][2],  const char *wFace[], const  char *wSuit[], unsigned int *nominal, unsigned int *wSortPlayer)
{
	 void swap(unsigned int * element1Ptr, unsigned int * element2Ptr);//функция обменивающая карты в ячейках, на которые показывают указатели

     unsigned int counter[FACES]={0};//сколько одинаковых номиналов карт на руках у игрока
     unsigned int counter1[SUITS]={0};//сколько одинаковых мастей карт на руках у игрока
     
     unsigned int k1 = 0;//переменная для запоминания номинала первой пары карт
	 unsigned int k2 = 0;//переменная для запоминания номинала второй пары карт

     size_t t = 0;//приоритет комбинации
	
     
     for(unsigned int r = 0; r < 5; ++r)
     {
         ++counter[wPlayer[r][1]];//считаем, сколько одинаковых номиналов карт на руках у игрока
         ++counter1[wPlayer[r][0]];//считаем, сколько одинаковых мастей карт на руках у игрока
		 wSortPlayer[r] = wPlayer[r][1];//заполняем массив номиналов карт, которые на руках у игрока
		
     }
     
     for( unsigned int p = 0; p < FACES; ++p)
     {
         if(counter[p] == 2 )//если две одинаковые карты
         {
             t++;//увеличиваем счетчик на единицу, так как на руках  пара карт
			 if(t == 1)//если на руках одна пара
			 {
				 k1 = p;//запоминаем номинал первой пары
			 }
			 else if(t == 2)//если на руках две пары
			 {
				 k2 = p;//запоминаем номинал второй пары
			 }
         }
         else if(counter[p] == 3 )//если на руках три одинаковые карты
         {
             printf("\nThe hand contains a three %s\n", wFace[p] );//выводим сообщение и номинал карты на экран
			 t = 3;//приоритет комбинации
         }
         else if(counter[p] == 4 )//еесли на руках четыре одинаковые карты
         {
             printf("\nThe hand contains a four %s\n", wFace[p] );//выводим сообщение и номинал карты на экран
			 t = 6;//приоритет комбинации
         }
     }
     
     if(t == 1)//если на руках одна пара
     {
        printf("\nThe hand contains a pair %s\n", wFace[k1] );//выводим сообщение и номинал карты на экран
		*nominal = k1;//запомнить номинал первой пары
		
		
	 }
     else if(t == 2)//если на руках две пары
     {
         printf("\nThe hand contains a two pairs %s and  %s\n", wFace[k1],wFace[k2]  );//выводим сообщение и номинал карты на экран
		 *nominal = k1 + k2;//считаем сумму номиналов двух пар
     }

     //если одинаковых номиналов карт на руках у игрока нет, проверяем комбинацию флеш(пять карт одной масти)
	 if( t == 0)
	 {
        for( size_t p = 0; p < SUITS; ++p)
        {  
		    if(counter1[p] == 5 )//если пять карт одной масти
            {
		        printf("\nThe hand contains a flush %s\n", wSuit[p] );//выводим сообщение и масть карты на экран
				
				t = 5;//приоритет комбинации
		    }
	    }
		for (size_t i = 0; i < 5; ++i )
		{
			*nominal += wSortPlayer[i];//вычисляем сумму номиналов карт одной масти
		}
       // printf("\nNominal_flash %d\n", *nominal );
	 }

     //сортировка массива карт, которые имеются на руках у игрока
     for( size_t i = 0; i < 4; ++i)
     {
		 for( size_t j = 0; j < 4; ++j)
         {
			 if(wSortPlayer[j] < wSortPlayer[j+1])
			 {
				 swap(&wSortPlayer[j], &wSortPlayer[j+1]);//обмен элементов
			 }		
		 }
	 }

     //тестирование программы
	 printf("\nSort:\n ");
	 for( size_t i = 0; i < 5; ++i)
     {		
		  printf("%s\n ", wFace[ wSortPlayer[i]] );
	 }


     //определить, идут ли карты по порядку, но масти разные
     if( t == 0)
	 {	    
       if(wSortPlayer[4]-1 == wSortPlayer[3] && wSortPlayer[3]-1 == wSortPlayer[2] && wSortPlayer[2]-1 == wSortPlayer[1] && wSortPlayer[1]-1 == wSortPlayer[0])
	   {
		   printf("The hand contains a straight from %s to %s/ \n", wFace[wSortPlayer[0]], wFace[wSortPlayer[4]]);
		   for (size_t i = 0; i < 5; ++i )
		   {
			   *nominal += wSortPlayer[i];//вычисляем сумму номиналов карт одной масти
		   }
		   t = 4;
	   }
	 }
      return t;
}

//функция обменивающая карты в ячейках, на которые показывают указатели
void swap(unsigned int * element1Ptr, unsigned int * element2Ptr)
{
	unsigned int temp = * element1Ptr;
    * element1Ptr = * element2Ptr;
    * element2Ptr = temp;
}

//печать результата оценивания карт
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
