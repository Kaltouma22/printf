#include "main.h"

/**
 * _printf - Write a function that produces output according to a format.
 * @format: The format string is composed of zero or more directives.
 *
 * Return: the lenght of string
 */

int _printf(const char *format, ...)
{
	int i;
	va_list args;
	int lied = 0;

	va_start(args, format); /* Initialize the va_list */

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			char character = format[i];

			write(1, &character, 1);
			lied++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char character = va_arg(args, int);

				write(1, &character, 1);
				lied++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				lied += write(1, str, strlen(str));
			}
			else if (format[i] == '%')
			{
				char percent = '%';

				write(1, &percent, 1);
				lied++;
			}
		}
	}
	va_end(args);

	return (lied);
}
