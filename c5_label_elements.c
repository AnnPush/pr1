/*Промаркируйте элементы двумерного массива sales размером 3 на 5,
чтобы показать порядок, в котором они устанавливаются в нуль в
следующем фрагменте программы:

for (row = 0; row <= 2; ++row) {
for (column = 0; column <= 4; ++column) {
sales[row][column] = 0;
}
}
/*

#include <stdio.h>
#define SIZE1 2
#define SIZE2 4

int main(void)
{
	int sales[SIZE1][SIZE2];//объявляем двумерный массив
	
        //устанавливаем элементы в нуль
	for (int row = 0; row <= SIZE1; row++ )
	{
		for (int column = 0; column <= SIZE2; column++ )
		{
			sales[row][column] = 0;
		}
	}

        //выводим массив на экран
        for (int row = 0; row <=SIZE1; row++ )
	{
		puts("");

        for (int column = 0; column <= SIZE2; column++ )
		{
	        printf("[%d][%d] = %d  ", row, column, sales[row][column] );
		}
	}

}
