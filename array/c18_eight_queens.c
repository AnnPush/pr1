#include <stdio.h>
#define SIZE 8


void printArray(int b[][SIZE], int size);//печать массива

int main(void)
{
	int board[SIZE][SIZE] = {0};
    int accessibility[SIZE][SIZE] = {0};

}
//end main

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
//end printArray
