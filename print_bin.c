#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_bin - convert to binary
 * @b: number in decimal
 * 
 * Return: number of chars printed
 */

int print_bin(va_list b)
{
   unsigned int len, baseten, j, digit, n, num;
   int count = 0;

   n = va_arg(b, unsigned int);
   if (n != 0)
   {
       num = n;
       len = 0;
       while (num != 0)
       {
           num /= 2;
           len++;
       }
       baseten = 1;
       for (j = 1; j <= len - 1; j++)
           baseten *= 2;
       for (j = 1; j <= len; j++)
       {
           digit = n / baseten;
            _putchar(digit + '0');
           count++;
           n -= digit * baseten;
           baseten /= 2;
       }
    }
    else 
    {
        _putchar('0');
        return (1);
    }
    return (count);
}