/*Напишите программу, которая вводит символы с клавиатуры и проверяет их 
с помощью каждой из функций библиотеки обработки символов. Программа 
должна выводить значения, возвращаемые каждой функцией.*/

/*Библиотека обработки символов(<ctype.h>)
Функции:
1) int isdigit(int c);
2) int isalpha(int c);
3) int isalnum(int c);
4) int isxdigit(int c);
5) int islower(int c);
6) int isupper(int c);
7) int tolower(int c);
8) int toupper(int c);
9) int isspece(int c);
10) int iscntrl(int c );
11) int ispunct(int c);
12) int isprint(int c);
13) int isgraph(int c ).
*/

#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char c;
	int a;
	puts("Enter character :\n");
	scanf("%c", &c);
	printf("Character: %c\n ", c);
	
	/*1) int isdigit(int c) Возвращает истинное значение, 
	если с - цифра, и 0(ложное) в противном случае*/
	printf("isdigit \'%c\' = %d\n", c, isdigit(c));
	
	/* Enter character:
	9
	Character: 9
	isdigit '9' = 1
	
	Enter character:
	a
	Character: a
	isdigit 'a' = 0*/
	
	/*2) int isalpha(int c) Возвращает истинное значение, 
	если с -буква, и 0 в противном случае*/
	printf("isalpha \'%c\' = %d\n", c, isalpha(c));
	
	/* Enter character:
	9
	Character: 9
	isalpha '9' = 0
	
	Enter character:
	a
	Character: a
	isalpha 'a' = 1024*/
	
	/*3) int isalnum(int c) Возвращает истинное значение, 
	если с -буква или цифра, и 0 в противном случае*/
	printf("isalnum \'%c\' = %d\n", c, isalnum(c));
	
	/* Enter character:
	9
	Character: 9
	isalnum '9' = 8
	
	Enter character:
	a
	Character: a
	isalnum 'a' = 8
	
	Enter character:
	#
	Character: #
	isalnum '#' = 0*/
	
	/*4) int isxdigit(int c) Возвращает истинное значение, 
	если с - символ шестнадцатеричной системы, и 0 в противном случае*/
	printf("isxdigit \'%c\' = %d\n", c, isxdigit(c));
	
	/* Enter character:
	F
	Character: F
	isxdigit 'F' = 4096
	
	Enter character:
	V
	Character: V
	isxdigit 'V' = 0*/
	
	/*5) int islower(int c) Возвращает истинное значение, 
	если с -буква нижнего регистра, и 0 в противном случае*/
	printf("islower \'%c\' = %d\n", c, islower(c));
	
	/* Enter character:
	А
	Character: A
	islower 'A' = 0
	
	Enter character:
	a
	Character: a
	islower 'a' = 512*/
	
	/*6) int isupper(int c) Возвращает истинное значение, 
	если с -буква верхнего регистра, и 0 в противном случае*/
	printf("isupper \'%c\' = %d\n", c, isupper(c));
	
	/* Enter character:
	А
	Character: A
	isupper 'A' = 256
	
	Enter character:
	a
	Character: a
	isupper 'a' = 0*/
	
	/*7) int tolower(int c) Если с - буква верхнего регистра, tolower
	возвращает ее эквивалент в нижнем регистре. В противном случае
	функция возвращает значение аргумента без изменений.*/
	printf("tolower \'%c\' = %c\n", c, tolower(c));
	
	/* Enter character:
	А
	Character: A
	tolower 'A' = a
	*/
	
	/*8) int toupper(int c) Если с - буква нижнего регистра, toupper
	возвращает ее эквивалент в верхнем регистре. В противном случае
	функция возвращает значение аргумента без изменений.*/
	printf("toupper \'%c\' = %d\n", c, toupper(c));
	
	/* Enter character:
	А
	Character: a
	tolower 'a' = A
	
	/*9) int isspace(int c) Возвращает истинное значение, если
	 с - пробельный символ, т. е. новая строка ('\n'), пробел (' '),
	 перевод страницы ('f'), возврат каретки ('\r'), 
	 горизонтальная табуляция ('\t') или вертикальная табуляция ('\v'),
	 и 0 в противном случае.*/
	printf("isspace \'%c\' = %с\n", c, isspace(c));
	
	/*9) int isspace(int c) Возвращает истинное значение, если
	 с - пробельный символ, т. е. новая строка ('\n'), пробел (' '),
	 перевод страницы ('f'), возврат каретки ('\r'), 
	 горизонтальная табуляция ('\t') или вертикальная табуляция ('\v'),
	 и 0 в противном случае.*/
	printf("isspace \'%c\' = %d\n", c, isspace(c));
	
	/* Enter character:
	'\n'
	Character: '\n'
	isspace '' = 8192
	
	2
	Character: 2
	isspace '2' = 0
	*/
	
	/*10) int iscntrl(int c) Возвращает истинное значение, если
	 с - управляющий символ и 0 в противном случае.
	 
	 Управляющие символы (или как их ещё называют — 
	 escape-последовательность) — символы которые выталкиваются 
	 в поток вывода, с целью форматирования вывода или печати 
	 некоторых управляющих знаков С.
	 
	 1.  \r   возврат каретки в начало строки;
	 2.  \n   новая строка;
	 3.  \t   горизонтальная табуляция
	 4.  \v   вертикальная табуляция
	 5.  \»   двойные кавычки
	 6.  \’   апостроф
	 7.  \\   обратный слеш
	 8.  \0   нулевой символ
	 9.  \?   знак вопроса
	 10. \a   сигнал бипера (спикера) компьютера
	 */
	printf("iscntrl \'%c\' = %d\n", c, iscntrl(c));
	
	/* Enter character:
	'\t'
	Character: '\t'
	iscntrl '' = 2
	
	3
	Character: 3
	iscntrl '3' = 0
	
	/*11) int ispunct(int c) Возвращает истинное значение, если
	 с - печатаемый символ, не являющийся пробелом, буквой или цифрой,
	 и 0 в противном случае.
	 */
	printf("ispunct \'%c\' = %d\n", c, ispunct(c));
	
	/* Enter character:
	?
	Character: ?
	ispunct '?' = 4
	
	3
	Character: 3
	ispunct '3' = 0
	*/
	*/
	
}
