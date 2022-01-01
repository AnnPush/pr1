#include <iostream>

using std :: cout;
using std :: endl;

//определение абстрактного типа данных (ADT) Time

class Time{
	public:
	Time();//конструктор
	void setTime(int, int, int);//установка часов, минут, секунд
	void printMilitary();//напечатать в военном формате
	void printStandard();//напечатать в стандартной форме
	private:
	int hour;//0-23
	int minute;//0-59
	int second;//0-59
}; //конец класса Time

//конструктор Time инициализирует каждый элемент данных нулем
//гарантирует, что объект Time создается в согласованном состоянии
Time :: Time() {hour = minute = second = 0;}

//Установить новое значение Time (по военному времени).
//Проверить допустимость значений.
//Недействительные значения заменить нулем.
void Time :: setTime(int h, int m, int s)
{
	hour = (h >= 0 && h < 24) ? h : 0;
	minute = (m >= 0 && m < 60) ? m : 0;
	second = (s >= 0 && s < 60) ? s : 0;
}//конец функции setTime

//Напечатать Time в военном формате
void Time :: printMilitary()
{
	cout << (hour < 10 ? "0" : "") << hour << ":"
	<< (minute < 10 ? "0" : "") <<minute;
}//конец функции printMilitary

//напечатать Time в стандартном формате


 
