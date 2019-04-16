/*(Комиссии по продажам) Используйте одномерный массив для решения этой задачи. Компания
оплачивает работу своих продавцов с учетом комиссионных. Продавцы получают $200 в неделю плюс 9% от
их валового сбыта. Например, продавец, валовый сбыт которого составляет $3000 в неделю, получит
$200 плюс 9% от $3000, или в сумме $470. Напишите программу на С (с массивом счетчиков)
для определения количества продавцов, заработок которыхпопал в каждый из следующих диапазонов (предположите,
что заработок каждого продовца округлен до целочисленного значения):
a) $200–299
b) $300–399
c) $400–499
d) $500–599
e) $600–699
f) $700–799
g) $800–899
h) $900–999
i) $1000 and over*/


#include <stdio.h>
#define SALES_SIZE 20     //определение размера массива валовых продаж
#define FREQUENCY_SIZE 9  //определение размера массива частот, FREQUENCY - частота, диапазон частот


int main(void)
{
	// инициализировать счетчик частот нулями
	int frequency[FREQUENCY_SIZE] = {0};

	// поместить валовый доход продавцов в массив
	int  sales[SALES_SIZE] = {3410, 2549, 5637, 5746, 3988, 6765, 2389, 2457, 4858, 3310,
                                5458, 5354, 2362, 809, 653, 4210, 8763, 738, 1294, 2754};

	// выбрать значение валового дохода и рассчитать зарплату,
	//а затем отнять фиксированный доход 200$ и поделить на 100,
	//чтобы рассчитать индекс массива частот, который позволит определить элемент приращения, salary зарплата
	for (size_t salary = 0; salary < SALES_SIZE; ++salary)
	{
		sales[salary] = sales[salary] * 9/10000;
		
		//если зарплата $1000 и выше
		if(sales[salary] > FREQUENCY_SIZE - 1)
		{
			sales[salary] = FREQUENCY_SIZE - 1;
		}
		++frequency[sales[salary]];		
	}

	// вывести результаты
	printf("%s%19s\n", "Salary", "Frequency");

	// вывести диапазоны зарплат и частоты в формате таблицы
	for (size_t rating = 0; rating < FREQUENCY_SIZE; ++rating)
	{
		int n = (rating + 2) * 100;

		if(n > 999)
		{
			printf("$%d and over %10d\n", n, frequency[rating]);
		}
		else
		{
			 printf("$%d-%d%17d\n", n, n + 99, frequency[rating]);
		}       
        }
}
