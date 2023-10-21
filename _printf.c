#include "main.h"

/**
  * _printf - my own prrintf
  * @format: The character or string or integer to print
  * Return: count - the number of characters printed
  */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				_putchar('%');
				count++;
			}

			else if (*format == 'c')
			{
				int ch = va_arg(args, int);

				_putchar(ch);
				count++;
			}

			else if (*format == 's')
			{
				char *str = va_arg(args, char*);

				while (*str != '\0')
				{
					_putchar(*str);
					str++;
					count++;
				}
			}

			else if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args, int);

				int printed = print_integers(num);
				return (printed);
			}
		}

		else
		{
			_putchar(*format);
			count++;
		}

		format++;
	}

	va_end(args);

	return (count);
}
