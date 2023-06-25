#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>


int _printf(const char *format, ...);
char *from_int_to_string(int value);
void str_concat(int pos, char *str1, char *str2);
int _strlen(const char *str);
int get_size(int len,const char *format, va_list args);

#endif /*MAIN_H*/
