/*Что делает следующая функция?*/

#include <stdio.h>
#define SIZE 10

void someFunction(const int b[], size_t startIndex, size_t size);//прототип функции

int main(void)
{
	int a[SIZE] = { 8, 3, 1, 2, 6, 0, 9, 7, 4, 5 };//инициализация одномерного массива

	puts("Answer is:");
	someFunction(a, 0, SIZE);
	puts("");
}

//определение рекурсивной функции, которая переворачивает массив
void someFunction(const int b[], size_t startIndex, size_t size)
{
        //проверяем, начальный индекс меньше размера массива
        if (startIndex < size)
	{
	        //функция вызывает саму себя, при этом увеличивается индекс на 1
		someFunction(b, startIndex + 1, size);
		printf("%d ", b[startIndex]);
	}
}
 /*
 Вывод:
 Answer is:
 5 4 7 9 0 6 2 1 3 8 
*/
