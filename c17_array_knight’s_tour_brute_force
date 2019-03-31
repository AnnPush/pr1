//Обход конем. Метод грубой силы

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8
#define SIZES 1000

void printArray(int b[][SIZE], int size);//печать массива


int main(void)
{
	int board[SIZE][SIZE] = {0};//инициализация массива нулями

	int horizontal[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};//описания ходов по горизонтали
	int vertical[SIZE] = {-1, -2, -2, -1, 1, 2, 2, 1};//описание ходов по вертикали

	int a[SIZES] = {0};//массив, в который записывается количество клеток обхода 

        int currentRow = 3;//координата строки клетки, с которой начинается обход
	int currentColumn = 4;//координата столбца клетки, с которой начинается обход

	int moveNumber;//в какую клетку осуществляется ход

        int n = 0;//счетчик (значение, записываемое в клетку(от 1 до 64)

	int preRow = 0;//строка предыдущго положения коня
	int preColumn = 0;//столбец предыдущего положения коня
	
	
	srand(time(NULL));//рандомизировать генератор случаййных чисел текущим временем
        
	//количество обходов
	for(int i = 0; i < SIZES; i++)
	{
	    //обнулить все клетки поля
            for( int r = 0; r< SIZE; r++)
            {
                for( int u = 0; u < SIZE; u++)
		{
		    board[r][u] = 0;
		}
	    }
	    do
            {
                if(board[currentRow][currentColumn] == 0)//если значение клетки равно нулю
	        {
		    n++;//увеличить счетчик на единицу
	            board[currentRow][currentColumn] = n;//в текущую клетку записать новое значение
                }
	        else
	        {
		    currentRow = preRow;//строке текущего положения коня присваивается предыдущее значение
	            currentColumn = preColumn;//столбцу текущего положеия коня присваивается предыдущее значение
	        }
		       
	        moveNumber = rand() % 7;//выбрать случайное значение от 0 до 7

	        preRow =  currentRow;//строка предыдущему присваивается текущее значение 
	        preColumn = currentColumn;//столбец предыдущему присваивается текущее значение 
		 
		//изменение положения коня
	        currentRow += vertical[moveNumber];
	        currentColumn += horizontal[moveNumber];
	           
	} while( currentRow < 8 && currentColumn < 8 && currentRow >= 0  && currentColumn >= 0 );
	
	//присвоить начальные значения
	currentRow = 3;
	currentColumn = 4;
	
	a[i] = n;//записать количество обходов в массив
	
	n = 0;//обнулить счетчик
	
	//puts(" ");
	//printArray(board, SIZE);
	}
	
	for ( int j =0; j < SIZES; j++)
	{
	    printf("%4d", a[j]);//распечатать массив с числом обходов и их продолжительностью
	}
	puts(" ");
}

void printArray( int b[][SIZE], int size)
{
	for(int i = 0; i < size; i++)
	{
		puts(" ");
		for(int j = 0; j < size; j++)
		{
			printf("%4d", b[i][j]);
		}
	}
}
