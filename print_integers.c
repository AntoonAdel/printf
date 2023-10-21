#include "main.h"

/**
  * print_integers - print any integer
  * @num: The integer to print
  * Return: printed - the number of integers printed
  */

int print_integers(int num)
{
	char buffer[32];
	int printed = 0;
	int a = 0, n;

	if (num < 0)
	{
		_putchar('-');
		printed++;
		num = -num;
	}

	while (num > 0)
	{
		buffer[a++] = '0' + (num % 10);
		num /= 10;
		printed++;
	}

	for (n = a - 1; n >= 0; n--)
	{
		_putchar(buffer[n]);
	}

	return (printed);
}
