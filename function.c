#include "main.h"

/**
 * get_size - size of buffer
 *
 * @len: length
 * @format: format
 * @args: args
 * Return: size
 */

int get_size(int len, const char *format, va_list args)
{
	int i, size, value;
	char *str;

	size = 0;
	for (i = 0; i <= len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%' || format[i] == 'c')
			{
				size++;
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				value = va_arg(args, int);
				str = from_int_to_string(value);
				size += _strlen(str);
			}
			else if (format[i] == 's')
			{
				size += _strlen(va_arg(args, char*));
			}
			else
				size += 2;
		}
		else
		{
			size++;
		}
	}
	return (size);
}
/**
 * fill_buf - fill the buffer
 *
 * @size: size of buffer
 * @format: format
 * @args: args
 * @buf: buffer
 */
void fill_buf(int size, const char *format, va_list args, char *buf)
{
	int i, j, value;
	char *str;

	for (i = 0, j = 0; i <= size; i++)
	{
		if (format[j] == '%')
		{
			j++;
			if (format[j] == 'd' || format[j] == 'i')
			{
				value = va_arg(args, int);
				str = from_int_to_string(value);
				str_concat(i, buf, str);
				i += _strlen(str) - 1;
				j++;
			}
			else if (format[j] == 's')
			{
				str = va_arg(args, char*);
				str_concat(i, buf, str);
				i += _strlen(str) - 1;
			}
			else if (format[j] == 'c')
				buf[i] = va_arg(args, int);
			else
			{
				buf[i] = '%';
				j--;
			}
			j++;
			if (format[j] == '%')
				j++;
		}
		else
		{
			buf[i] = format[j];
			j++;
		}
	}
}
