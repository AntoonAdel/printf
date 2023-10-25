#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>
#include <unistd.h>

/**
  * print_chars - print the chars
  * @myString: the char to print
  * Return: printedChars - the number of printed chars
  */

int print_chars(char *myString)
{
	int printedChars = 0;

	while (*myString != NULL)
	{
		printedChars += _putchar(*myString++);
	}

	return (printedChars);
}

/**
  * print_integers - print any integer
  * @myInt: The integer to print
  * Return: printedChars - the number of integers printed
  */

int print_integers(int myInt)
{
	char myBuffer[11];
	int printedChars = 0;
	int a = 0, n;

	if (myInt < 0)
	{
		printedChars += _putchar('-');
		myInt *= -1;
	}

	while (myInt > 0)
	{
		myBuffer[a++] = myInt % 10;
		myInt /= 10;
	}

	for (n = a - 1; n >= 0; n--)
	{
		printedChars += _putchar ('0' + myBuffer[n]);
	}

	return (printedChars);

}

/**
  * _printf - my own prrintf
  * @format: The character or string or integer to print
  * Return: count - the number of characters printed
  */

int _printf(const char *format, ...)
{
	va_list myVariableList;
	int printedChars = 0;
	int myInt;
	char *myString;
	char myChr;

	va_start(myVariableList, format);
	for (char *myPtr = format; *myPtr != NULL; myPtr++)
	{
		if (*myPtr == '%')
		{
			switch (*(++myPtr))
			{
				case '%':
					printedChars += _putchar('%');
					printedChars++;
					break;
				case 'c':
					myChr = va_arg(myVariableList, int);
					printedChars += _putchar(myChr);
					break;
				case 'i':
					myInt = va_arg(myVariableList, int);
					printedChars += print_integers(myInt);
					break;
				case 'd':
					myInt = va_arg(myVariableList, int);
					printedChars += print_integers(myInt);
					break;
				case 's':
					myString = va_arg(myVariableList, char*);
					printedChars += print_chars(myString);
					break;
			}
		}

		else
		{
			printedChars += _putchar(*myPtr);
		}
	}
	return (printedChars);
}
