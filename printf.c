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
	int char_count = 0;

	va_start(args, format); /* Initialize the va_list */

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			char character = format[i];

			write(1, &character, 1);
			char_count++;
		}
		else
		{
			i++;
			if (format[i] == 'c')
			{
				char character = va_arg(args, int);

				write(1, &character, 1);
				char_count++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char *);

				char_count += write(1, str, strlen(str));

			}
			else if (format[i] == '%')
			{
				char percent = '%';

				write(1, &percent, 1);
				char_count++;
			}
		}
	}
	_putchar(BUF_FLUSH);
	va_end(args);

	return (char_count);
}
