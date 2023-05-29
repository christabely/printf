#include "main.h"

/**
 * _strlen - Returns the length of a string
 * @s: The string to measure
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;

	return (len);
}

/**
 * _strrev - Reverses a string
 * @str: The string to reverse
 */
void _strrev(char *str)
{
	int start = 0;
	int end = _strlen(str) - 1;
	char temp;

	while (start < end)
	{
		temp = *(str + start);
		*(str + start) = *(str + end);
		*(str + end) = temp;
		start++;
		end--;
	}
}
