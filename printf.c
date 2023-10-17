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
	int char_count = 0;

	va_list args;
	va_start(args, format);

	if (!format)
		return (-1);

	for (i = 0; format[i]; i++)
	{
		if (format[i] != '%')
		{
			char character = format[i];

			char_count += write(1, &character, 1);
		}
		else
		{
			i++;
			if (format[i] == 'c' || format[i] == '%')
			{
				char character = va_arg(args, int);

				char_count += write(1, &character, 1);
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				char_count += write(1, str, strlen(str));
			}
		}
	}
	va_end(args);
	return (char_count);
}	
