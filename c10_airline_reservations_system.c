/*
Небольшая авиакомпания недавно приобрела компьютер для новой автоматизированной системы
предварительной продажи билетов. Президент компании попросил вас написать на С программное
обеспечение для новой системы. Вы должны составить программу для бронирования мест на каждом
рейсе единственного самолета авиакомпании (его вместимость: 10 мест).
Ваша программа должна отображать на экране следующее меню альтернативных возможностей:
Пожалуйста, введите 1 для "первого класса".
Пожалуйста, введите 2 для Ээкономичного класса".
Если оператор вводит 1, то ваша программа должна забронировать место в отделении
первого класса (места 1-5). Если оператор вводит 2, то ваша программа должна забронировать
место в экономичном классе (место 6-10). После этого ваша программа должна напечатать 
посадочный талон с указанием номера места пассажира и информации о том, находится
ли оно в определении первого или экономичного класса самолета. Для представления схемы 
мест для пассажиров самолета используйте одномерный массив. Инициализируйте все элементы 
массива нулями, чтобы показать, что все места свободны. По мере бронирования мест 
устанавливайте соответствующие элементы массива в 1 для указания на то, что это место 
больше не является свободным.Конечно, программа никогда не должна бронировать уже
забронированное место. Если первый класс заполнен, программа должна запросить оператора, 
приемлемо ли бронирование места в экономичном классе(и наоборот). В случае положительного 
ответа произведите соответствующее бронирование места. В случае отрицательного ответа 
выведите сообщение "Следующий рейс через 3 часа"
*/

#include <stdio.h>
#define SIZE 10

void printBoardingPass(int a[], int size);//печать посадочных мест
void firstClass(int a[], int size, int p);//бронировать место в первом классе
void economySection(int a[], int size, int p);//бронировать место в эконом классе
int seatFirst(int a[], int size);//количество занятых мест в первом классе
int seatsEconomy(int a[], int size);//количество занятых мест во втором классе

int main(void)
{
	int capacity[SIZE] = {0};//инициализировать массив мест в самолете нулями
	int type_class;//тип класса
	int n = 0;//количество занятых мест в самолете
	int t = 0;//флаг, что клиент не хочет бронировать оставшиеся места
	int reserve_economy, reserve_first;
	int pf, pe;//количество занятых мест в первом классе и эконом классе

	puts("Welcome to \"Airline Reservations System\"!\n");
	printBoardingPass(capacity, SIZE);//печать мест в самолете

	while( n != 10 && t == 0)//если есть пустые места, и клиент не отказывается бронировать место
	{
	   //выбор типа класса
	   printf("%s", "\n\nEnter please type 1 for \"first class\"\n Please type 2 for \"economy\"\n");
	   scanf("%d", &type_class);
	   
           //клиент выбрал первый класс
	   if (type_class == 1)
	   {
                  pf = seatFirst(capacity, SIZE);//определить количество занятых мест в первом классе
		  //если все места заняты
		  if (pf == 5)
		  {
		      //предложить клиенту забронировать место в эконом классе
		      printf("%s", "\nTo reserve a seat in economy section? ( yes - 1, no - 0 ):\n");
		      scanf("%d", &reserve_economy);

		      if ( reserve_economy == 1)
		      {
			       economySection(capacity, SIZE, pe);//бронировать место в эконом классе
		      }
		      else if (reserve_economy == 0)
		      {
			      t = 1; //флаг, клиент не желает бронироваать имеющееся место
		      }

		  }
		  else 
		  {
			  firstClass(capacity, SIZE, pf);//бронировать место в первом классе

		  }
	      printBoardingPass(capacity, SIZE);//печать мест в самолете
	   }
	   
	   //клиент выбрал эконом класс
	   else if (type_class == 2)
	   {
		  pe = seatsEconomy(capacity, SIZE);//количество занятых мест в эконом классе
		  
		  //все места заняты
		  if (pe == 5)
		  {
		      //предложить клиенту забронировать место в первом классе
		      printf("%s", "\nTo reserve a seat in first section? ( yes - 1, no - 0 ):\n");
		      scanf("%d", &reserve_first);

		      if ( reserve_first == 1)
		      {
			      firstClass(capacity, SIZE, pf);//бронировать место в первом классе
		      }
		      else if (reserve_first == 0)
		      {
			      t = 1; //флаг, клиент не желает бронировать имеющееся место
		      }
		  }
		  else 
		  {
			   economySection(capacity, SIZE, pe);//бронировать место в эконом классе
		  }
          printBoardingPass(capacity, SIZE);//печать мест в самолете
	    
	   }
	   else
	   {
		   puts("Error!");//ошибка
	   }
	   n = seatFirst(capacity, SIZE) + seatsEconomy(capacity, SIZE);//определить количество занятых мест в самолете
	}
	
		 puts("\nNext flight leaves in 3 hours.");//следующий рейс через три часа	
}

int seatFirst(int a[], int size)
{
	int nf = 0;

	for (int i = 0; i < 5; i++ )
	{
		if (a[i] == 1)
		{
			nf++;
		}
	}
	return nf;
}

int seatsEconomy(int a[], int size)
{
	int ne = 0;

	for (int i = 5; i < size; i++ )
	{
		if (a[i] == 1)
		{
			ne++;
		}
	}
	return ne;
}

void firstClass(int a[], int size, int p)
{
	
  int pp = p;//количество занятых мест в первом классе

  for (int i = 0; i <5; i++)
  {
 	 if(pp == p && a[i] == 0)//если количество мест не изменилось, и выбранное место не занято
	 {
	        //бронируем место
		a[i] = 1;
		printf("First Class. Seat: %d\n", i + 1);
		puts("Happy flying!");
		pp++;//изменяем количество забронированных мест
	 }
  }

	
}

void economySection(int a[], int size, int p)
{
	int pp = p;//количество занятых мест в эконом классе

  for (int i = 5; i <size; i++)
  {
 	 if(a[i] == 0 && pp == p)//если количество мест не изменилось, и выбранное место не занято
	 {
	        //бронируем место
		a[i] = 1;
		printf("Economy Section. Seat: %d\n", i + 1);
		puts("Happy flying!");
		pp++;//изменяем количество забронированных мест
	}
  }
	
}
void printBoardingPass(int a[], int size)
{
	for (int i = 0; i < size; i++ )
	{
		printf("Seat: %d(%d)   ", i + 1, a[i]);
	}
}

