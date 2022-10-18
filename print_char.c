#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * print_char - writes the character to stdout
 *@c: the character to print
 *  
 * Return: 1
 */
int print_char(va_list c)
{
    unsigned char my_char;

    my_char = va_arg(c, int);
    _putchar(my_char);
    return (1);
}

/**
 * print_percentage - write %
 * 
 * Return: 1
 */
int print_percentage(void)
{
    _putchar('%');
    return (1);
}