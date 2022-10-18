#include "main.h"

/**
 * print_dec - write integer to c stdout
 * @i: integer to print
 * 
 * Return: size of the output text
 */

int print_int(va_list d)
{
    int len, baseten, j, digit, n, count = 0, num;

    n = va_arg(d, int);
    if (n != 0)
    {
        if (n < 0)
        {
            _putchar('-');
            count++;
        }
        num = n;
        len = 0;
        while (num != 0)
        {
            num /= 10;
            len++;
        }
        baseten = 1;
        for (j = 1; j <= len - 1; j++)
            baseten *= 10;
        for (j = 1; j <= len; j++)
        {
            digit = n / baseten;
            if (n < 0)
                _putchar((digit * -1) + 48);
            else
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