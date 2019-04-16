/*
Ход конем
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 8

void printArray(int b[][SIZE2], int size);//печать массива

int main(void)
{
	int board[SIZE][SIZE] = {0};//инициализация массива нулями
	int horizontal[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};//описания ходов по горизонтали
	int vertical[SIZE] = {-1, -2, -2, -1, 1, 2, 2, 1};//описание ходов по вертикали

        int currentRow = 3;//строка текущего положения  коня
	int currentColumn = 4;//столбец текущего положения коня
	int moveNumber;//в какую клетку осуществляется ход
        int n = 1;//счетчик (значение, записываемое в клетку(от 1 до 64)
	int preRow;//строка предыдущго положения коня
	int preColumn;//столбец предыдущего положения коня
	
	srand(time(NULL));//рандомизировать генератор случаййных чисел текущим временем

	do
        { 
           if(board[currentRow][currentColumn] == 0)//если значение клетки равно нулю
	   {
	      board[currentRow][currentColumn] = n;//в текущую клетку записать новое значение
              n++;//увеличить счетчик на единицу
	   }
	   else
	   {
	      currentRow = preRow;//строке текущего положения коня присваивается предыдущее значение
	      currentColumn = preColumn;//столбцу текущего положеия коня присваивается предыдущее значение
	   }
		       
	   moveNumber = rand() % 7;//выбрать случайное значение

	   preRow =  currentRow;//строка предыдущему присваивается текущее значение 
	   preColumn = currentColumn;//столбец предыдущему присваивается текущее значение 
	   
	   //изменение положения коня
	   currentRow += vertical[moveNumber];
	   currentColumn += horizontal[moveNumber];
	           
	} while( currentRow < SIZE && currentColumn < SIZE && currentRow >= 0  && currentColumn >= 0 );
		   
	
	

	printArray(board, SIZE);
}

void printArray( int b[][SIZE], int size)
{
	for(int i = 0; i < size; i++)
	{
		puts(" ");
		for(int j = 0; j < size; j++)
		{
			printf("%d", b[i][j]);
		}
	}
}

