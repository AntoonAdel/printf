#include "main.h"

/**
  * print_integers - print any integer
  * @myInt: The integer to print
  * Return: printedChars - the number of integers printed
  */

int print_integers(int myInt)
{
	char myBuffer[32];
	int printedChars = 0;
	int a = 0, n;

	if (myInt < 0)
	{
		_putchar('-');
		myInt *= -1;
		printedChars++;
	}

	while (myInt > 0)
	{
		myBuffer[a++] = myInt % 10;
		myInt /= 10;
	}

	for (n = a - 1; n >= 0; n--)
	{
		_putchar ('0' + myBuffer[n]);
		printedChars++;
	}

	return (printedChars);
}
