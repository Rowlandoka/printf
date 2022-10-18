#ifndef _MAIN_H
#define _MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_dec(va_list d);

/**
 * struct func_code - Struct format
 * 
 * @fs: The specifiers
 * @f: associated function
 */

typedef struct func_code
{
    char *fs;
    int (*f)(va_list);
} func_c;

#endif