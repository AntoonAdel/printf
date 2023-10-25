#include "main.h"
/**
  * print_chars - print the chars
  * @myString: the char to print
  * Return: printedChars - the number of printed chars
  */

int print_chars(char *myString)
{
	int printedChars = 0;

	while (*myString != '\0')
	{
		printedChars += _putchar(*myString++);
	}

	return (printedChars);
}
