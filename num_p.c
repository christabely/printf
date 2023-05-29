#include "main.h"

/**
 * print_number - Prints a number passed to this function
 * @args: List of arguments
 * Return: The number of characters printed
 */
int print_number(va_list args)
{
    int n;
    int div;
    int len;
    unsigned int num;

    n = va_arg(args, int);
    div = 1;
    len = 0;

    if (n < 0)
    {
        len += write_character('-');
        num = (unsigned int)(-n);
    }
    else
    {
        num = (unsigned int)n;
    }

    for (; num / div > 9; )
    {
        div *= 10;
    }

    for (; div != 0; )
    {
        len += write_character('0' + num / div);
        num %= div;
        div /= 10;
    }

    return len;
}

/**
 * print_unsigned_number - Prints an unsigned number
 * @n: Unsigned integer to be printed
 * Return: The number of characters printed
 */
int print_unsigned_number(unsigned int n)
{
    int div;
    int len;
    unsigned int num;

    div = 1;
    len = 0;
    num = n;

    for (; num / div > 9; )
    {
        div *= 10;
    }

    for (; div != 0; )
    {
        len += write_character('0' + num / div);
        num %= div;
        div /= 10;
    }

    return len;
}

