#include "main.h"

/**
 * print_decimal - Prints a decimal number
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_decimal(va_list args, int *count)
{
	int num = va_arg(args, int);
	int digits = 0;
	int sign = 0;

	if (num == 0)
	{
		*count += charwrite('0', count);
		return (1);
	}

	if (num < 0)
	{
		sign = 1;
		num = -num;
		*count += charwrite('-', count);
	}

	while (num > 0)
	{
		*count += charwrite((num % 10) + '0', count);
		num /= 10;
		digits++;
	}

	return (digits + sign);
}

/**
 * print_unsigned - Prints an unsigned integer
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_unsigned(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int digits = 0;

	if (num == 0)
	{
		*count += charwrite('0', count);
		return (1);
	}

	while (num > 0)
	{
		*count += charwrite((num % 10) + '0', count);
		num /= 10;
		digits++;
	}

	return (digits);
}

/**
 * print_binary - Prints a binary number
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_binary(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int digits = 0;
	int binary[32];

	if (num == 0)
	{
		*count += charwrite('0', count);
		return (1);
	}

	while (num > 0)
	{
		binary[digits] = num % 2;
		num /= 2;
		digits++;
	}

	while (digits > 0)
	{
		*count += charwrite(binary[digits - 1] + '0', count);
		digits--;
	}

	return (digits);
}

/**
 * print_octal - Prints an octal number
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_octal(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int digits = 0;
	int octal[32];

	if (num == 0)
	{
		*count += charwrite('0', count);
		return (1);
	}

	while (num > 0)
	{
		octal[digits] = num % 8;
		num /= 8;
		digits++;
	}

	while (digits > 0)
	{
		*count += charwrite(octal[digits - 1] + '0', count);
		digits--;
	}

	return (digits);
}

/**
 * print_hex - Prints a hexadecimal number (lowercase)
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_hex(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int digits = 0;
	char hex[32];
	int rem;

	if (num == 0)
	{
		*count += charwrite('0', count);
		return (1);
	}

	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			hex[digits] = rem + '0';
		else
			hex[digits] = (rem - 10) + 'a';
		num /= 16;
		digits++;
	}

	while (digits > 0)
	{
		*count += charwrite(hex[digits - 1], count);
		digits--;
	}

	return (digits);
}

/**
 * print_hex_upper - Prints a hexadecimal number (uppercase)
 * @args: The va_list argument
 * @count: Pointer to the counter of characters printed
 *
 * Return: The number of characters printed
 */
int print_hex_upper(va_list args, int *count)
{
	unsigned int num = va_arg(args, unsigned int);
	int digits = 0;
	char hex[32];
	int rem;

	if (num == 0)
	{
		*count += charwrite('0', count);
		return (1);
	}

	while (num > 0)
	{
		rem = num % 16;
		if (rem < 10)
			hex[digits] = rem + '0';
		else
			hex[digits] = (rem - 10) + 'A';
		num /= 16;
		digits++;
	}

	while (digits > 0)
	{
		*count += charwrite(hex[digits - 1], count);
		digits--;
	}

	return (digits);
}
