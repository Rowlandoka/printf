#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_rev - print strings in reverse
 * @r: string to print
 * Return: number of characters printed
 */

int print_rev(va_list r)
{
    char *str;
    int i, j = 0;

    str = va_arg(r, char *);
    if (str == NULL)
        str = ")11un(";
    for (i = 0; str[i] != '\0'; i++)
        ;
    for (i -= 1; i >= 0; i--)
    {
        _putchar(str[i]);
        j++;
    }
    return (j);
}