#include "main.h"

int _write_char(char c);
char *rev_string(char *str);

/**
 * print_hexadecimal - prints number
 * @list: arguments
 * Return: to characs printed
 */
int print_hexadecimal(va_list list)
{
	int len = 0, num = va_arg(list, int);
	char *hex_rep, *rev_hex;
	int rem_num;

	if (num == 0)
	{
		_write_char('0');
		return (1);
	}

	hex_rep = malloc(sizeof(char) * 100);
	if (hex_rep == NULL)
		return (-1);

	while (num != 0)
	{
		rem_num = num % 16;
		if (rem_num > 9)
			hex_rep[len] = hex_check(rem_num, 'x');
		else
			hex_rep[len] = rem_num + '0';
		num = num / 16;
		len++;
	}

	hex_rep[len] = '\0';
	rev_hex = rev_string(hex_rep);
	if (rev_hex == NULL)
	{
		free(hex_rep);
		return (-1);
	}

	write_base(rev_hex);
	free(hex_rep);
	free(rev_hex);

	return (len);
}

/**
 * hex_check - Checks for function call
 * @num: integer to convert to characts
 * @x: function calling
 * Return: to charac
 */
int hex_check(int num, char x)
{
	char *hex = "abcdef";
	char *Hex = "ABCDEF";

	num = num - 10;
	if (x == 'x')
		return (hex[num]);
	else
		return (Hex[num]);
}
