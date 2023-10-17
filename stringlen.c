#include "main.h"

/**
 * _strlin - get the lenght of the string
 *
 * @sen: the pointer to the string to print
 *
 * Return: the lenght of the string
 */
int _strlin(char *sen)
{
	int len = 0;

	if (sen[len] != '\0')
	{
		len++;
	}
	return (len);
}
