#include <stdio.h>
#include <stdlib.h>
#include <time.h>

enum Status {CONTINUE, WON, LOST};

int rollDice(void);

int main()
{
	int sum;
	int myPoint = 0;
	int bankBalance = 1000;
	int wager = 0;

	printf("%s\n", "Enter your wager: ");
	scanf("%d", &wager);

	while(wager > bankBalance)
	{
		printf("%s\n", "You don't have that bankBalance! Enter your wager again: ");
	    scanf("%d", &wager);
	}

	enum Status gameStatus;

	srand(time(NULL));

	sum = rollDice();

	switch( sum )
	{

		case 7:
		case 11:
		gameStatus = WON;
	    break;

	    case 2:
		case 3:
		case 12:
			gameStatus = LOST;
		break;

		default:
			gameStatus = CONTINUE;
		myPoint = sum;
		printf( "Point is %d\n", myPoint);
		break;
    }

	while( gameStatus == CONTINUE)
	{
		sum = rollDice();
		if( sum == myPoint )
		{
			gameStatus = WON;
		}
		else
		{
			if( sum == 7 )
			{
				gameStatus = LOST;
			}
		}
	}

	if( gameStatus == WON )
	{
		printf( "%s", "Player wins\n" );
		printf( "You now have a balance of %d", (bankBalance += wager));
	}
	else
	{
		printf( "%s", "Player loses\n" );
		bankBalance -= wager;
		printf( "You now have a balance of %d", bankBalance);

        if(bankBalance == 0)
			printf( "%s", "You've busted!\n" );


	}
}

int rollDice( void )
{
	int die1;
	int die2;
	int workSum;

	die1 = 1 + (rand() % 6 );
	die2 = 1 + (rand() % 6 );

	workSum = die1 + die2;

	printf( "Player rolled %d + %d = %d\n", die1, die2, workSum);

	return workSum;
}
