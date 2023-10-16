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
	char ch;

	va_start(pami, format);

	for (obi = 0; format[obi] != '\0'; obi++)
	{
		if (format[obi] != '%')
		{
			_putchar(format[obi]);
			lied++;
		}
		else if (format[obi + 1] == 'c')
		{
			ch = va_arg(pami, int);
			_putchar(ch);
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
			_putchar('%');
		}
		lied += 1;
	}
		va_end(pami);
		return (lied);
}
