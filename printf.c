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
			putchar(format[i]);
			lied++;
		}
		else
		{
			i++;
			switch ((format[i]))
			{
				case 'c':{
					char character = va_arg(args, int);

					_putchar(character);
					lied++;
					break;
				}
				case 's':{
					char *str = va_arg(args, char *);

					lied += printf("%s", str);
					break;
				}
				case '%':{
					putchar('%');
					lied++;
					break;
				}
				default:
					/*
					 * Handle an unknown format
					 * specifier here if needed
					 */
					break;
			}
		}
	}
	va_end(args);

	return (lied);
}
