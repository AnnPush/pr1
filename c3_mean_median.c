/*(Mean, Median and Mode Program Modifications). 
  Программа вычисляет среднее, медиану и модус данных.


#include <stdio.h>
#define SIZE 99

void mean(const unsigned int answer[]);
void median(unsigned int anser[]);
void mode(unsigned int freq[], unsigned const int answer[]);
void bubbleSort(unsigned int a[]);
void printArray(unsigned const int a[]);

int main(void)
{
	unsigned int frequency[10] = {0};

	unsigned int response[SIZE] =
	{	6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
	    7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
		6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
		7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
		6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
		7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
		5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
		7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
		7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
		4, 5, 6, 1, 6, 5, 7, 8, 7};

	mean(response);
	median(response);
	mode(frequency, response);
}

void mean(const unsigned int answer[])
{
	printf("%s\n%s\n%s\n", "********", " Mean", "********");

	unsigned int total = 0;

	for (size_t j = 0; j <SIZE; ++j)
	{
		total += answer[j];
	}
		printf("The mean is average value of the data\n"
		"items. The mean is equal to the total of]n"
		"all the data items divided by the number\n"
		"of data items (%u). The mean value for\n"
		"this run is: %u / %u = %.4f\n\n",
			SIZE, total, SIZE, (double) total / SIZE);
}

void median(unsigned int answer[])
{
	printf("\n%s\n%s\n%s\n%s",
		"********", "Median", "********",
		"The unsorted array of responses is");

	printArray(answer);

	bubbleSort(answer);

	printf("%s", "\n\nThe sorted array is");
	printArray(answer);

	printf("\n\nThe median is element %u of\n"
	        "the sorted %u element array. \n"
			"For this run the median is %u\n\n",
				SIZE / 2, SIZE, answer[SIZE / 2]);	                    
}

void mode(unsigned int freq[], const unsigned int answer[])
{
	printf("\n%s\n%s\n%s\n", "********", "  Mode", "********");

	for (size_t rating = 1; rating <= 9; ++rating)
	{
		freq[rating] = 0;
	}

	for (size_t j = 0; j < SIZE; ++j)
	{
		++freq[answer[j]];
	}

	printf("%s%11s%19s\n\n%54s\n%54s\n\n",
		   "Response", "Frequensy", "Histogram",
		   "1 1 2 2", "5 0 5 0 5");
	unsigned int largest = 0;
	unsigned int modeValue = 0;

	for (size_t rating = 1; rating <= 9; ++rating)
	{
		printf("%8u%11u        ", rating, freq[rating]);

	    if(freq[rating] > largest)
	    {
			largest = freq[rating];
		    modeValue = rating;
	    }

	    for(unsigned int h = 1; h <= freq[rating]; ++h)
	    {
		    printf("%s", "*");
	    }

	    puts("");
	}

	printf("\nThe mode is the most frequent value.\n"
	"For this run the mode is %u which occurred"
	" %u times. \n", modeValue, largest);
}

void bubbleSort(unsigned int a[])
{
	for(unsigned int pass = 1; pass < SIZE; ++pass)
	{
		for(size_t j = 0; j < SIZE - 1; ++j)
		{
			if(a[j] > a[j + 1])
			{
				unsigned int hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
	}
}

void printArray(const unsigned int a[])
{
	for(size_t j = 0; j < SIZE; ++j)
	{
		if(j%20 == 0)
		{
			puts("");
		}

		printf("%2u", a[j]);
	}
}


Измените программу так, чтобы функция mode при
расчете наиболее вероятного значения могла обрабатывать случай нескольких равных сумм.
Также измениете функцию median так, чтобы в массиве с четным числом элементов усреднялись
значения двух элементов в середине.
*/

#include <stdio.h>
#define SIZE 99

//прототипы функций
void mean(const unsigned int answer[]);
void median(unsigned int anser[]);
void mode(unsigned int freq[], unsigned const int answer[]);
void bubbleSort(unsigned int a[]);
void printArray(unsigned const int a[]);

int main(void)
{
	unsigned int frequency[10] = {0};//инициализация массива частот

	//инициализация массива откликов
	unsigned int response[SIZE] =
	{	6, 7, 8, 9, 8, 7, 8, 9, 8, 9,
	    7, 8, 9, 5, 9, 8, 7, 8, 7, 8,
		6, 7, 8, 9, 3, 9, 8, 7, 8, 7,
		7, 8, 9, 8, 9, 8, 9, 7, 8, 9,
		6, 7, 8, 7, 8, 7, 9, 8, 9, 2,
		7, 8, 9, 8, 9, 8, 9, 7, 5, 3,
		5, 6, 7, 2, 5, 3, 9, 4, 6, 4,
		7, 8, 9, 6, 8, 7, 8, 9, 7, 8,
		7, 4, 4, 2, 5, 3, 8, 7, 5, 6,
		4, 5, 6, 1, 6, 5, 7, 8, 7};

	//обработка откликов
	mean(response);
	median(response);
	mode(frequency, response);
}

//вычислить среднее всех значений откликов
void mean(const unsigned int answer[])
{
	printf("%s\n%s\n%s\n", "********", " Mean", "********");

	unsigned int total = 0;

	for (size_t j = 0; j <SIZE; ++j)
	{
		total += answer[j];
	}
		printf("The mean is average value of the data\n"
		"items. The mean is equal to the total of]n"
		"all the data items divided by the number\n"
		"of data items (%u). The mean value for\n"
		"this run is: %u / %u = %.4f\n\n",
			SIZE, total, SIZE, (double) total / SIZE);
}

//сортировать массив и определить значение медианного элемента
void median(unsigned int answer[])
{
	printf("\n%s\n%s\n%s\n%s",
		"********", "Median", "********",
		"The unsorted array of responses is");

	printArray(answer);//вывести несортированный массив

	bubbleSort(answer);//сортировать массив

	printf("%s", "\n\nThe sorted array is");
	printArray(answer);//вывести сортированный массив

        //если четное число элементов в массиве, то находим среднее двух серединных элементов и выводим медианный элемент
	if (SIZE%2 == 0)
	{
	    printf("\n\nThe median are elements %u and of %u\n"
	        "the sorted %u element array. \n"
			"For this run the median is %u\n\n",
				SIZE / 2, SIZE / 2 + 1, SIZE, (answer[SIZE / 2] + answer[SIZE / 2 + 1]) / 2);
	}
	//если нечетное число элементов в массиве, то вывести медианный элемент
	else
	{
    	printf("\n\nThe median is element %u of\n"
	        "the sorted %u element array. \n"
			"For this run the median is %u\n\n",
				SIZE / 2, SIZE, answer[SIZE / 2]);	 
	}	                    
}

//определить наиболее частый отклик
void mode(unsigned int freq[], const unsigned int answer[])
{
	printf("\n%s\n%s\n%s\n", "********", "  Mode", "********");
	
	//инициализировать частоты нулями
	for (size_t rating = 1; rating <= 9; ++rating)
	{
		freq[rating] = 0;
	}
	
	//суммировать частоты
	for (size_t j = 0; j < SIZE; ++j)
	{
		++freq[answer[j]];
	}
	
	//вывести заголовки колонок результатов
	printf("%s%11s%19s\n\n%54s\n%54s\n\n",
		   "Response", "Frequensy", "Histogram",
		   "1 1 2 2", "5 0 5 0 5");
	unsigned int largest[10] = {0};
	unsigned int modeValue[10] = {0};
	unsigned int count = 1;
	
	//вывести результаты
	for (size_t rating = 1; rating <= 9; ++rating)
	{
		printf("%8u%11u        ", rating, freq[rating]);
                
		//отслеживает значение модуса и наибольшее значение частоты
	        if(freq[rating] > largest[count])
	        {
			largest[count] = freq[rating];
			modeValue[count] = rating;

	        }
		else if(freq[rating] == largest[count])//если несколько равных сумм
		{
		        count++;
			largest[count] = freq[rating];
			modeValue[count] = rating;
		}
            
	    //вывести столбцовую гистограмму значений частот
	    for(unsigned int h = 1; h <= freq[rating]; ++h)
	    {
		    printf("%s", "*");
	    }

	    puts("");
	}

        //вывести значения модуса
        while(count > 0)
	{		    
	    printf("\nThe mode is the most frequent value.\n"
	    "For this run the mode is %u which occurred"
	    " %u times. \n", modeValue[count], largest[count]);
	    --count;
	}
}

//функция, сортирующая массив путем пузырьковой сортировки
void bubbleSort(unsigned int a[])
{
	for(unsigned int pass = 1; pass < SIZE; ++pass)
	{
		for(size_t j = 0; j < SIZE - 1; ++j)
		{
			if(a[j] > a[j + 1])
			{
				unsigned int hold = a[j];
				a[j] = a[j + 1];
				a[j + 1] = hold;
			}
		}
	}
}

//вывод содержимого массива
void printArray(const unsigned int a[])
{
	for(size_t j = 0; j < SIZE; ++j)
	{
		if(j%20 == 0)
		{
			puts("");
		}

		printf("%2u", a[j]);
	}
}
