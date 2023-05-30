#include "main.h"
/**
 * _puts - prints string with newline
 * @z: string to print
 *
 * Return: void
 */
int _puts(char *z)
{
	char *u = z;

	while (*z)
		_putchar(*z++);
	return (z - u);
}
/**
 * _putchar - writes char c to stdout
 * @c: character to print
 * Return: On success 1
 * On error, -1 is returned, and error is set appropriately.
 */
int _putchar(int c)
{
	static int i;
	static char buf[OUTPUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUTPUT_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
