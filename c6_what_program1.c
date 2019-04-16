/*Что делает следующая программа?*/


#include <stdio.h>
#define SIZE 10

int whatIsThis(const int b[], size_t p);//объявляем прототип функции

int main(void)
{
	int x;
        
	
	int a[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };//инициализируем массив числами

	x = whatIsThis(a, SIZE);

	printf("Result is %d\n", x);//вывод результата - суммы всех элементов массива
}

//определение рекурсивной функции
int whatIsThis(const int b[], size_t p)
{
        //проверяем, базовый ли это случай
	if(1 == p)
	{
		return b[0];
	}
	else
	{
		return b[p-1] + whatIsThis(b, p-1);//функция вызывает саму себя, происходит сложение всех элементов массива
	}
}

/*Выводит: Result is 55*/
