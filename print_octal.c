#include "main.h"


/**
 * print_octal - unsigned int argument is converted to unsigned octal
 * @o:unsigned to be converted
 * 
 * Return: size of the output 
 */

int print_octal(va_list o)
{
   unsigned int len, baseten, j, digit, n, num;
   int count = 0;

   n = va_arg(o, unsigned int);
   if (n != 0)
   {
       num = n;
       len = 0;
       while (num != 0)
       {
           num /= 8;
           len++;
       }
       baseten = 1;
       for (j = 1; j <= len - 1; j++)
           baseten *= 8;
       for (j = 1; j <= len; j++)
       {
           digit = n / baseten;
            _putchar(digit + '0');
           count++;
           n -= digit * baseten;
           baseten /= 8;
       }
    }
    else 
    {
        _putchar('0');
        return (1);
    }
    return (count);
}