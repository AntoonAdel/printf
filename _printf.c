#include "main.h"

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
					printedChars += putchar('%');
					printedChars++;
					break;
				case 'c':
					myChr = va_arg(myVariableList, int);
					printedChars += putchar(myChr);
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
			printedChars += putchar(*myPtr);
		}
	}
	return (printedChars);
}
