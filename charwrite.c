#include "main.h"

/**
 * charwrite - Writes a character to the standard output
 * @c: The character to write
 * @count: Pointer to the counter of characters printed
 *
 * Return: On success, 1. On error, -1.
 */
int charwrite(char c, int *count)
{
	return (write(1, &c, 1));
}
