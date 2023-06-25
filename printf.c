
#include "main.h"

/**
 * _printf - function that produces output according to a format
 * same as original printf
 * 
 * @format: format is a character string.
 * The format string is composed of zero or more directives
 * Return: number of bytes printed
 */

int _printf(const char *format, ...)
{
	char *buf;
	int size = 1;
	va_list args;
	int len = 0;
	int i;
	int j;
	int value;
	char *str;

	len = _strlen(format);
	va_start(args, format);
	for (i = 0; i <= len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				size ++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				value = va_arg(args, int);
				if (value < 0)
					size++;
				str = from_int_to_string(value);
				size += _strlen(str);
			}
		}
		else
		{
			size++;
		}
	}
	va_end(args);
	size++;
	buf = malloc(size);
