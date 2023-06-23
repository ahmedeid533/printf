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
    va_start(args, format);
    for (i = 0, j = 0; i <= size; i++)
    {
        if (format[j] == '%')
        {
            j++;
            if (format[j] == '%')
            {
                j++;
                buf[i] = '%';
            }
            else if (format[j] == 'd' || format[j] == 'i')
            {
                value = va_arg(args, int);
                str = from_int_to_string(value);
                if (value < 0)
                { 
                    str_concat(i, buf, "-");
                    i++;
                }
                str_concat(i, buf, str);
                i += _strlen(str);
                j++;
            }
        }
        else
        {
            buf[i] = format[j];
            j++;
        }
    }
    va_end(args);
    buf[size] = '\0';
    return (write(1, &buf[0], size + 1));
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

    if (value < 0)
    {
        value = -value;
    }
    while (temp != 0)
    {
        temp /= 10;
        len++;
    }
    str = malloc(len + 1);
    len--;
    str[len + 1] = '\0';
    for (;len >= 0; len--)
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
 * 
 * 
 */
 int _strlen(const char *str)
 {
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
 }