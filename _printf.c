#include <stdio.h>
#include <stdlib.h>
#include "main.h"

/**
 * search_function - function to search formats for _printf
 * @format: format (char, string, int, decimal) 
 * Return: Null or function.
 */

int (*search_function(const char *format))(va_list)
{
    unsigned int i = 0;
    func_c search_f[] = {
        {"c", print_char},
        {"s", print_string},
        {"i", print_int},
        {"d", print_dec},
        {"r", print_rev},
        {"b", print_bin},
        {"u", print_unsig},
        {"o", print_octal},
        {"x", print_x},
        {"X", print_X},
        {"R", print_rot13},
        {NULL, NULL}
    };
    while (search_f[i].fs)
    {
        if (search_f[i].fs[0] == (*format))
            return (search_f[i].f);
        i++;
    }
    return NULL;
}

/**
 * _printf - function that produces output to a format
 * @format: format(char, int, string, decimal)
 * Return: size the output text.
 */

int _printf(const char *format, ...)
{
    va_list arg;
    int (*f)(va_list);
    unsigned int i = 0, fprint = 0;

    if (format == NULL)
        return (-1);
    va_start(arg, format);
    while (format[i])
    {
        while (format[i] != '%' && format[i])
        {
            _putchar(format[i]);
            fprint++;
            i++;
        }
        if (format[i] == '\0')
            return (fprint);
        f = search_function(&format[i + 1]);
        if (f != NULL)
        {
            fprint += f(arg);
            i += 2;
            continue;
        }
        if (!format[i + 1])
            return (-1);
        _putchar(format[i]);
        fprint++;
        if (format[i + 1] == '%')
            i += 2;
        else
            i++;
    }
    va_end(arg);
    return (fprint);
}