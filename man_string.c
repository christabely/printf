#include "main.h"
/**
 * print_reversed - prints string
 * @arg: string arguments
 * Return: characters
 */
int print_reversed(va_list arg)
{
    int len;
    char *str;
    char *ptr;

    str = va_arg(arg, char *);
    if (str == NULL)
        return (-1);
    ptr = reverse_string(str);
    if (ptr == NULL)
        return (-1);
    for (len = 0; ptr[len] != '\0'; len++)
        write_character(ptr[len]);
    free(ptr);
    return (len);
}

/**
 * rotate_13 - Changes string to ROT13
 * @list: convertion of strings
 * Return: changed characters
 */
int rotate_13(va_list list)
{
    int i;
    int x;
    char *str;
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(list, char *);
    if (str == NULL)
        return (-1);
    for (i = 0; str[i] != '\0'; i++)
    {
        for (x = 0; x <= 52; x++)
        {
            if (str[i] == alphabet[x])
            {
                write_character(rot13[x]);
                break;
            }
        }
        if (x == 53)
            write_character(str[i]);
    }
    return (i);
}

