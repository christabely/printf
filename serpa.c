#include "main.h"

/**
 * print_string_custom - Prints a string with custom conversion specifier %S
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_string_custom(va_list args, int *count)
{
	int i, len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
		str = "(null)";

	for (i = 0; str[i] != '\0'; i++)
	{
		if ((str[i] > 0 && str[i] < 32) || str[i] >= 127)
		{
			*count += charwrite('\\', count);
			*count += charwrite('x', count);
			*count += charwrite('0', count);
			*count += charwrite('0', count);
			*count += print_hex_upper_single(str[i], count);
			len += 5;
		}
		else
		{
			*count += charwrite(str[i], count);
			len++;
		}
	}

	return (len);
}

/**
 * print_pointer - Prints a pointer address
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_pointer(va_list args, int *count)
{
	unsigned long int ptr = (unsigned long int)va_arg(args, void *);
	char *hex = "0123456789abcdef";
	int digits = 0;

	*count += charwrite('0', count);
	*count += charwrite('x', count);

	if (ptr == 0)
	{
		*count += charwrite('0', count);
		return (3);
	}

	while (ptr != 0)
	{
		*count += charwrite(hex[ptr % 16], count);
		ptr /= 16;
		digits++;
	}

	return (digits + 3);
}

/**
 * print_reverse - Prints a string in reverse
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_reverse(va_list args, int *count)
{
	int i;
	char *str = va_arg(args, char *);
	int len = _strlen(str);

	for (i = len - 1; i >= 0; i--)
		*count += charwrite(str[i], count);

	return (len);
}

/**
 * print_rot13 - Prints a string in ROT13 encoding
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_rot13(va_list args, int *count)
{
	int i, j;
	char *str = va_arg(args, char *);
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int len = _strlen(str);
	int converted = 0;

	for (i = 0; i < len; i++)
	{
		converted = 0;
		for (j = 0; j < 52; j++)
		{
			if (str[i] == alpha[j])
			{
				*count += charwrite(rot13[j], count);
				converted = 1;
				break;
			}
		}
		if (!converted)
			*count += charwrite(str[i], count);
	}

	return (len);
}
