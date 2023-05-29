#include "main.h"
#include <stdio.h>
/**
 * reverse_string - Reverses string
 * @s: string
 * Return: to character
 */
char *reverse_string(char *s)
{
int len;
int head;
char tmp;
char *dest;

for (len = 0; s[len] != '\0'; len++)
{}

dest = malloc(sizeof(char) * len + 1);
if (dest == NULL)
return (NULL);

_memcpy(dest, s, len);
for (head = 0; head < len; head++, len--)
{
tmp = dest[len - 1];
dest[len - 1] = dest[head];
dest[head] = tmp;
}
return (dest);
}

/**
 * write_base_string - points character
 * @str: string
 */
void write_base_string(char *str)
{
int i;

for (i = 0; str[i] != '\0'; i++)
write_character(str[i]);
}

/**
 * get_base_length - cals length of num
 * @num: number
 * @base: calculate base
 * Return: to integer
 */
unsigned int get_base_length(unsigned int num, int base)
{
unsigned int length;

for (length = 0; num > 0; length++)
{
num = num / base;
}
return (length);
}

/**
 * _memcpy - memory copy
 * @destination: destination
 * @source: where to copy
 * @n: bytes
 * Return: to destination
 */
char *_memcpy(char *destination, char *source, unsigned int n)
{
unsigned int i;

for (i = 0; i < n; i++)
destination[i] = source[i];
destination[i] = '\0';
return (destination);
}
