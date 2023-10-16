#ifndef _PRINT_F
#define _PRINT_F

#include <stdint.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define DEFAULT_NULL_STRING "(null)"
#define OUTPUT_BUF_SIZE 1024
#define BUFFER_RESET -1
#define LOWERCASE_ALPHABET 1
#define TO_UINT 2
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

typedef struct MyPara
{
	uint32_t unsign; /* Indicates unsigned value
			(1 for unsigned, 0 for signed) */
	uint32_t plus; /* Indicates presence of '+' sign
			(1 for present, 0 for absent) */
	uint32_t space; /* Indicates presence of ' ' (space)
			character (1 for present, 0 for absent) */
	uint32_t hashtag; /* Indicates presence of '#' character
			(1 for present, 0 for absent) */
	uint32_t zero; /* Indicates zero-padding
			(1 for zero-padding, 0 for default) */
	uint32_t minus; /* Indicates left alignment
			(1 for left, 0 for right alignment) */
	uint32_t width; /* Minimum field width for output */
	uint32_t prec; /* Precision for formatting */
	uint32_t h_modf1; /* Length modifier 1
			(1 for used, 0 for not used) */
	uint32_t h_modf2; /* Length modifier 2
			(1 for used, 0 for not used) */
} MyPara_t;

/* 
 * FormatHandler: Represents a format directive 
 * and its associated handler function
 */
typedef struct FormatHandler
{
	char *directive; /* Format directive string */
	int (*handler)(va_list, MyPara_t *); /* Function pointer to
						handle the formatting */
} FormatHandler_t;

struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

static struct fmt formats[] = {
	{'c', print_char},
	/*Other format specifiers and associated functions*/
	{0, NULL}
};

/*
 * Format specifiers and their
 * corresponding handler functions.
 */
static int write_char(char c)
{
	return write(1, &c, 1);
}

/**
 * Custom printf function to format and print text.
 *
 * @param format A format string containing format specifiers.
 * @param ... Additional arguments corresponding to format specifiers
 * @return The number of characters printed.
 */

extern struct fmt formats[];

int _printf(const char *format, ...);
void print_num(int num);

#endif
