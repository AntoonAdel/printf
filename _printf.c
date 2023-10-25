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
	const char *myPtr;

	va_start(myVariableList, format);
	if (*format == '\0')
	{
		return (-1);
	}
	for (myPtr = format; *myPtr != '\0'; myPtr++)
	{
		if (*myPtr == '%')
		{
			switch (*(++myPtr))
			{
				case '%':
					printedChars += _putchar('%');
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

	va_end(myVariableList);

	return (printedChars);
}
