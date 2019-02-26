/*
Напишите программу, в которой разыгрываются 1000 партий в крепс и которая отвечает на каждый из следующих вопросов:
а) Сколько игр выигрывается при первом бросании, втором бросании, ..., двадцатом бросании и после двадцатого бросания?
в) Сколько игр проигрывается при первом бросании, втором бросании, ..., двадцатом бросании и после двадцатого бросания?
с) Какова вероятность выигрыша в крепс?(Замечание: вы должны знать, что крепс является одной из самых справедливых игр в казино.
   Как вы полагаете, что это означает?)
d) Какова средняя продолжительность игры в крепс?
е) Увеличиваются ли шансы на выигрыш при большей продолжительности игры?
*/



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//перечисляемые константы, представляющие состояние игры
enum Status {CONTINUE, WON, LOST};

int rollDice(void);//прототип функции бросания кубиков

int main(void)
{
	srand(time(NULL));//рандомизировать генератор случайных чисел текущим временем

	int myPoint;//очки игрока
	enum Status gameStatus;
	int game = 1;//номер игры
	int won[22] = {0};//массив выигыш
	int lost[22] = {0};//массив проигрыш
	int sum_w = 0;//количество выигрышей
	int sum_l = 0;//количество проигрышей
	int sum_t = 0;//время игры
	float chances;//вероятность выигрыша

        while(game <= 1000)
	{
	    int start = clock();//время начала игры
	    int n = 1;
	    printf("\nGame %d\n", game);
	    puts("___________");
	    int sum = rollDice();//первое бросание кубиков

            //определить статус игры по выброшенной сумме
	    switch(sum)
	    {
	            //выигрыш при первом броске
		    case 7:
		    case 11:
			    gameStatus = WON;
			    ++won[n];
		        break;

                    //проигрыш при первом броске
		    case 2:
		    case 3:
		    case 12:
			    gameStatus = LOST;
			    ++lost[n];
		        break;

                    //запомнить пункт
		    default:
			    gameStatus = CONTINUE;
		            myPoint = sum;
			    printf("Point is %d\n", myPoint);
			break;
	    }

	   //пока игра не завершится	
   	    while (CONTINUE == gameStatus)
	    {
		    n++;
		    sum = rollDice();//бросить кубики снова

                    //определить статус игры
		    if (sum == myPoint)
		    {
			    gameStatus = WON;
			    ++won[n];
		    }
		    else
		    {
			    if (7 == sum)
			    {
				    gameStatus = LOST;
				    ++lost[n];
			    }
		    }
	    }

            //вывести сообщение о проигрыше или выигрыше
	    if (WON == gameStatus)
	    {
	        puts("___________");
		puts("Player wins");
	    }
	    else
	    {
	        puts("___________");
		puts("Player loses");
	    }
	    
            int end = clock();// время окончания игры
	    sum_t += end - start;//продолжительность игры
            game++;		
	}

        printf("\n%10s%12s\n", "WON", "LOST");
        
	//вывести сколько игр выигрывается и проигрывается при первом и последующих бросаниях
	for (int i = 1; i < 22; i++ )
	{   
		sum_w += won[i];
		sum_l += lost[i];
		
                printf("%2d%8d%11d   \n", i, won[i], lost[i]);
	}

	chances = (float)sum_w*100/1000;
	printf("\n Games are won: %d\n", sum_w);//количество выигрышей
	printf("\n Games are lost: %d\n", sum_l);//количество проигрышей
	printf("\n The chances of winning at craps: %.2f%\n", chances);//вероятность выигрыша в крепс
        printf("\n The average length of a game of craps: %d ms\n", sum_t/1000);//средняя продолжительность игры	
}

//функция отвечает за бросание кубиков
int rollDice(void)
{
	int die1 = 1 + (rand() % 6);//первый кубик
	int die2 = 1 + (rand() % 6);//второй кубик

	printf("Player rolled %d + %d = %d\n", die1, die2, die1 + die2);
	return die1 + die2;//возвратить сумму очков, выпавших на двух кубиках
}

/*Шансы на выигрыш при любой продолжительности игры остаются одинаковыми.*/
