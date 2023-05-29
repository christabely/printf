#include "main.h"

/**
 * print_char - Prints a character
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	*count += charwrite(c, count);

	return (1);
}

/**
 * print_string - Prints a string
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_string(va_list args, int *count)
{
	int i;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
		*count += charwrite(str[i], count);

	return (i);
}

/**
 * print_percent - Prints a percent symbol
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: Always returns 1
 */
int print_percent(va_list args, int *count)
{
	(void)args;

	*count += charwrite('%', count);

	return (1);
}
