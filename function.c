#include "main.h"

/**
 * get_size - size of buffer
 */

int get_size(int len,const char *format, va_list args)
{
	int i, size, value;
	char* str;

	size = 0;
	for (i = 0; i <= len; i++)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				size++;
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
	return (size);
}
