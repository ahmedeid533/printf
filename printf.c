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
	int size;
	va_list args;
	int len = 0;

	len = _strlen(format);
	va_start(args, format);
	size = get_size(len - 1, format, args);
	va_end(args);
	buf = malloc(size + 1);
	va_start(args, format);
	fill_buf(size, format, args, &buf[0]);
	va_end(args);
	return (write(1, &buf[0], size));
}
/**
 * from_int_to_string - convert from decimal to tring
 *
 * @value: the value in decimal passed
 * Return: string
 */
char *from_int_to_string(int value)
{
	char *str;
	int temp = value;
	int dec = 0;
	int len = 0;
	int chk = 0;

	if (value < 0)
	{
		value = -value;
		chk = 1;
	}
	while (temp != 0)
	{
		temp /= 10;
		len++;
	}
	len += chk;
	if (!value)
		len = 1;
	str = malloc(len + 1);
	if (chk)
		str[0] = '-';
	str[len] = '\0';
	len--;
	for (; len >= chk; len--)
	{
		dec = value % 10;
		if (dec >= 0 && dec <= 9)
			dec += 48;
		str[len] = dec;
		value /= 10;
	}
	return (str);
}
/**
 * str_concat - concat to strings
 *
 * @pos: position to start concating in
 * @str1: string concatin in
 * @str2: string will be concacted
 * Return: void
 */
void str_concat(int pos, char *str1, char *str2)
{
	int i;
	int j = pos;

	for (i = 0; i < _strlen(str2); i++)
	{
		str1[j] = str2[i];
		j++;
	}
}
/**
 * _strlen - srting length
 *
 * @str: string
 * Return: length
 */
int _strlen(const char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}
