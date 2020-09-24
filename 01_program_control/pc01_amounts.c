/*A person invests $1000.00 in a savings account yielding 5% interest. Assuming that
all interest is left on deposit in the account, calculate and print the amount of money
in the account at the end of each year for 10 years. Use the following formula for
determining these amounts:
a = p(1 + r)n
where
p is the original amount invested (i.e., the principal)
r is the annual interest rate (for example, .05 for 5%)
n is the number of years
a is the amount on deposit at the end of the nth year*/

#include <stdio.h>
#include <math.h>

int main(void)
{
   double principal = 1000.0;
   double rate = .05;
   
   printf("%4s%21s\n", "Year", "Amount on deposit");

   for( unsigned int year = 1; year <= 10; ++year)
   {
	  double amount = principal * pow(1.0 + rate, year);

	   printf("%4u%21.2f\n", year, amount);
   }
}
