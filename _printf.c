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
	int r_val;

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
					r_val = print_integers(myInt);
					if (r_val == -1)
					{
						return (-1);
					}
					printedChars += r_val;
					break;
				case 'd':
					myInt = va_arg(myVariableList, int);
					r_val = print_integers(myInt);
					if (r_val == -1)
					{
						return (-1);
					}
					printedChars += r_val;
					break;
				case 's':
					myString = va_arg(myVariableList, char*);
					r_val = print_chars(myString);
					if (r_val == -1)
					{
						return (-1);
					}
					printedChars += r_val;
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
