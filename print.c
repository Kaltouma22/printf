#include "main.h"

/**
 * _printf - Write a function that produces output according to a format.
 * @format: The format string is composed of zero or more directives.
 *
 * Return: the lenght of string
 */
int _printf(const char *format, ...)
{
	int obi, bu;
	va_list pami;
	int lied = 0;

	va_start(pami, format); /* Initialize the va_list */

	for (obi = 0; format[obi] != '\0'; obi++)
	{
		if (format[obi] != '%')
		{
			char character = format[obi];

			write(1, &character, 1);
			lied++;
		}
		else if (format[obi + 1] == 'c')
		{
			write(1, &format[obi + 2], 1);
			obi++;
		}
		else if (format[obi + 1] == 's')
		{
			bu = _strlin(va_arg(pami, char *));
			obi++;
			lied += (bu - 1);
		}
		else if (format[obi + 1] == '%')
		{
			char percent = '%';

			write(1, &percent, 1);
			obi++;
		}
		lied += 1;
	}
	va_end(pami);
	return (lied);
}
