#include "main.h"


/**
 * print_unsig - function that prints unsigned number
 * @u: unsigned number
 * 
 * Return: size of the output 
 */

int print_unsig(va_list u)
{
   unsigned int len, baseten, j, digit, n, num;
   int count = 0;

   n = va_arg(u, unsigned int);
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
           baseten *= 10;
       for (j = 1; j <= len; j++)
       {
           digit = n / baseten;
            _putchar(digit + '0');
           count++;
           n -= digit * baseten;
           baseten /= 10;
       }
    }
    else 
    {
        _putchar('0');
        return (1);
    }
    return (count);
}