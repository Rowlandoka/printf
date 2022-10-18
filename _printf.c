#include "main.h"

/**
 * convert - convert an integer to base
 * 
 * @num: integer to convert
 * @base: converted base 8,10 and 16
 * @return char* 
 */
char *convert(unsigned int num, int base)
{
    static char array[] = "0123456789ABCDEF";
    static char buffer[50];
    char *ptr;

    ptr = &buffer[49];
    *ptr = '\0';

    do {
        *--ptr = array[num % base];
        num /= base;
    } while (num != 0);
    return (ptr);
}

/**
 *_printf - function that produces output according to format
 * @format: The character string to pass
 * Return: Number of character printed
 */

int _printf(const char *format, ...)
{
    int i, j;
    char *s;

    va_list arg;
    va_start(arg, format);

    for (j = 0; format[j] != '\0'; j++)
    {
        while (format[j] != '%')
        {
           if(format[j] == '\0')
               return (j);
           _putchar(format[j]);
           j++;
        }
        j++;

        switch (format[j])
        {
        case 'c':
            i = va_arg(arg, int);
            _putchar(i);
            break;
        case 's':
            s = va_arg(arg, char *);
            puts(s);
            break;
        case '%':
            i = va_arg(arg, int);
            _putchar('%');
            break;
         case 'd':
                i = va_arg(arg, int);
                if (i < 0)
                {
                    i = -i;
                    _putchar('-');
                }
                puts(convert(i, 10));
                break;
        case 'o':
                i = va_arg(arg, unsigned int);
                puts(convert(i, 8));
                break;
        case 'x':
                i = va_arg(arg, unsigned int);
                puts(convert(i, 16));
        default:
            break;
        }
    }
    va_end(arg);
    return (j);
}
