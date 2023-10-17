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
		char character = format[i];
		char percent = '%';
		char *str = NULL;

		if (character != '%')
		{
			write(1, &character, 1);
			lied++;
		} else {
			i++;
			if (character == 'c')
			{
				character = va_arg(args, int);
				write(1, &character, 1);
				lied++;
			}
			else if (character == 's')
			{
				int len = strlen(str);

				str = va_arg(args, char *);
				write(1, str, len);
				lied += len;
			}
			else if (character == '%')
			{
				write(1, &percent, 1);
				lied++;
			}
		}
	}
	va_end(args);

	return (lied);
}
