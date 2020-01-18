
// Fig. 5.16: fig05_16.c
// Scoping.
#include <stdio.h>

void useLocal(void); 
void useStaticLocal(void); 
void useGlobal(void);

int x = 1; // global variable

int main(void)
{
	int x = 5; // local variable main

	printf("local x in outer score of main is %d\n", x);

	{ // start new score
		int x = 7; // local variable to new score

		printf("local x in inner score of main is %d\n", x);
	} // end new scope

	printf("local x in outer score of main is %d\n", x);

	useLocal(); //useLocal has automatic local x
	useStaticLocal(); // useStaticLocal has static local x
	useGlobal(); // useGlobal uses global x
	useLocal(); //useLocal reinitializes automatic local x
	useStaticLocal(); // static local x retains its prior value

	printf("\nlocal x in main is %d\n", x);
}

// useLocal reinitializes local variable x during each call
void useLocal(void)
{
	int x = 25; // initializes each time useLocal is called

	printf("\nlocal x is useLocal is %d after entering useLocal\n", x);
	++x;
	printf("local x in useLocal is %d before exiting useLocal\n", x);
}

// useStaticLocal initializes static local variable x only the first time
// the function is called; value of x is saved between calls to this function
void useStaticLocal(void)
{
	// initialized once
	static int x = 50;

	printf("\nlocal static x is %d on enterrng useStaticLocal\n", x);
		++x;
	printf("local static x is %d on exiting useStatic Local\n", x);
}

// function useGlobal modifies global variable x during each call
void useGlobal(void)
{
	printf("\nglobal x is %d on entering useGlobal\n", x);
	x *= 10;
	printf("global x is %d on exiting useGlobal\n", x);
}
