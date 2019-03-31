/*
Ход конем.
Программа, встретившись с равными показателями для двух или более клеток, решает,
какую клетку выбрать на основании результатов просмотра тех клеток, до которых можно добраться
из клеток с равными показателями. Программа должна перемещаться в ту клетку, следующее 
перемещение из которой пришлось бы на клетку с наименьшим показателем доступности.
*/


#include <stdio.h>
#define SIZE 8


void printArray(int b[][SIZE], int size);//печать массива
void accessibilityHeuristic(int b[][SIZE], int ac[][SIZE], int v[], int h[], int size);//функция высчитывает доступность каждой клетки на доске
int minM(int b[][SIZE], int ac[][SIZE], int v[], int h[], int size, int jj, int kk);//определить клетку, следующее 
//перемещение из которой прищлось бы на клетку с наименьшим показателем доступности.

int main(void)
{	
	int horizontal[SIZE] = {2, 1, -1, -2, -2, -1, 1, 2};//описания ходов по горизонтали
	int vertical[SIZE] = {-1, -2, -2, -1, 1, 2, 2, 1};//описание ходов по вертикали
	
	int board[SIZE][SIZE] = {0};//инициализация массива поле нулями
	int accessibility[SIZE][SIZE] = {0};//инициализация массива таблицы эвристики доступности нулями

	int z =0;//счетчик обходов для выведения его на печать
	
	int moveNumber;//в какую клетку осуществляется ход
        int n = 0;//счетчик количества клеток, в которые ходить нельзя
	int t = 1;//счетчик ходов от 1 до 64
	int m =0;//счетчик количества доступных ходов из определенной клетки

	int preRow;//строка предыдущго положения коня
	int preColumn;//столбец предыдущего положения коня

	int minRow = 0 ;//координата строки наименьшего показателя доступности
	int minColumn = 0;//координата столбца наименьшего показателя доступности
	
        int currentRow = 0;//строка текущего положения  коня
        int currentColumn = 0;//столбец текущего положения коня   
    
	int mNumber1;//показатель доступности  для текущей клетки
        int mNumber2;//показатель доступности клетки для предыдущей клетки
		
	//цикл для 64 обходов
	for( int j = 0; j< SIZE; j++)
	{
		for( int k = 0; k < SIZE; k++)
		{
	            z++;//увеличиваем счетчик обходов на единицу
	            printf("\nZ = %d\n", z);

                    //во все клетки на доске поместить нули
	            for( int r = 0; r< SIZE; r++)
	            {
		        for( int u = 0; u < SIZE; u++)
		        {
		           board[r][u] = 0;
		        }
	            }
		   
	            currentRow = j;//устанавливаем текущее значение строки
                    currentColumn = k;//устанавливаем текущее значение столбца  

                    n = 0;//обнулить счетчик количества клеток, в которые ходить нельзя
                    t = 1;//счетчик ходов от 1 до 64 вернуть в начальное положение
                    m =0;//обнулить счетчик количества доступных ходов из определенной клетки

                    minRow = 0;//обнулить координату строки наименьшего показателя доступности
                    minColumn = 0;//обнулить координату столбца наименьшего показателя доступности

		    board[j][k] = 1;//в текущую улетку записать 1
	    
	            while( n < SIZE )//если счетчик количество клеток, в которые нельзя ходтить меньше 8
                    {
                       accessibilityHeuristic(board, accessibility, vertical, horizontal, SIZE);//рассчитать доступность клеток
        
		       n = 0;//обнулить счетчик количества клеток, в которые ходить нельзя
		       t++;//увеличить на единицу счетчик ходов от 1 до 64

		       for(int i = 0; i < SIZE; i++)
		       {
                           preRow =  currentRow;//строка предыдущему присваивается текущее значение
	                   preColumn = currentColumn;//столбец предыдущему присваивается текущее значение 
	        
	                   /изменение положения коня
			   currentRow += vertical[i];
	                   currentColumn += horizontal[i];
                           
			   //если в результате хода, конь не попадет за границы поля, и клетка пустая
			   if(  currentRow < 8 && currentColumn < 8 && currentRow >= 0  && currentColumn >= 0 && board[currentRow][currentColumn] == 0 )
                           {
			        m++;//увеличить счетчик количества доступных ходов из определенной клетки
                               
			       //если это первая проверка или текущие значение доступности клетки меньше чем предыдущее
		               if( m == 1 || accessibility[currentRow][currentColumn] < accessibility[minRow][minColumn])
	                       {
			           //координаты минимального значения доступности равны координатам текущей клетки
		                   minRow = currentRow;
		                   minColumn = currentColumn;
        	               }
			       //если текущее значение доступности равно предыдущему значению досступности
			       else if(accessibility[currentRow][currentColumn] == accessibility[minRow][minColumn] )
        	               {
				    //	определить показатель доступности  для текущей клетки	     
        	                    mNumber1  =  minM(board, accessibility, vertical, horizontal, SIZE, currentRow, currentColumn);
				    
				    //определить показатель доступности  для предыдущей клетки
				    mNumber2  =  minM(board, accessibility, vertical, horizontal, SIZE, minRow, minColumn);
							 
				    //если показатель доступности текущей клетки меньше показателя доступности предыдущей клетки		 
	                            if(mNumber1 < mNumber2)
			            {
					minRow = currentRow;
		                        minColumn = currentColumn;				
				    } 
				}
			    }
			    //если в результате хода, конь  попадет за границы поля, или клетка занята значением
			    else
			    {
                                n++;//счетчик количества клеток, в которые ходить нельзя
			    }

			    currentRow = preRow;//строке текущего положения коня присваивается предыдущее значение
	                    currentColumn = preColumn;//столбцу текущего положеия коня присваивается предыдущее значение
		        }

		        m = 0;//обнулить счетчик количества доступных ходов из определенной клетки
	                   
		        if(t <= 64)//если счетчик ходов от 1 до 64 меньше или равен 64
			{
		             board[minRow][minColumn] = t;	 
			}
		        currentRow = minRow;//текущая координата строки равна координате минимальной доступности
	                currentColumn = minColumn;//текущая координата столбца равна координате минимальной доступности    	   
		   }
                   t = 0;//обнулить значение счетчика обхода поля
                   printArray(board, SIZE);//печать поля	   
        }  
	   
  }		
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
void accessibilityHeuristic(int b[][SIZE], int ac[][SIZE], int h[], int v[], int size)//определение доступности клеток
{
	int currentRow = 0;
	int currentColumn = 0;
	int preRow;
	int preColumn;

	int n = 0;


    for(int i = 0; i < 8; i++)
       {     
           for(int j = 0; j < 8; j++)
           {
			   for (int k = 0; k < 8; k++)
			   {
			       currentRow=i;    
		           currentColumn = j;

			       preRow =  currentRow;
	               preColumn = currentColumn;
		       
	               currentRow += v[k];
	               currentColumn += h[k];

		          if( currentRow < 8 && currentColumn < 8 && currentRow >= 0  && currentColumn >= 0 && b[currentRow][currentColumn] == 0)
		          {
					
			         n++;
		          }

			      currentRow = preRow;
	              currentColumn = preColumn;
			   }
			    
               ac[i][j] = n;
		       n=0;
          
	      }
		
       }
	
}



int minM(int b[][SIZE], int ac[][SIZE], int v[], int h[], int size, int jj, int kk//определение клетки с минимальной доступностью
{	
     int mNumber;

     int m =0;

     int preRow;
     int preColumn;

     int minRow = 0 ;
     int minColumn = 0;

     int  currentRow = jj;
     int  currentColumn = kk;  
     
     for(int i = 0; i < SIZE; i++)
     {
	 preRow =  currentRow;
	 preColumn = currentColumn;
	        
	 currentRow += v[i];
	 currentColumn += h[i];

	 if(  currentRow < 8 && currentColumn < 8 && currentRow >= 0  && currentColumn >= 0 && b[currentRow][currentColumn] == 0 )
	 {
             m++;
                
             if( m == 1 || ac[currentRow][currentColumn] < ac[minRow][minColumn] )
	     {					  
	         minRow = currentRow;
		 minColumn = currentColumn;				   
             }	
         }
         currentRow = preRow;
	 currentColumn = preColumn;
    }
		       
    mNumber = ac[minRow][minColumn];
    return mNumber;
}
