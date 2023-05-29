#include "main.h"
/**
 * _printf - print formatted string
 * @format: string
 * Return: to count of characs printed
 */
int _printf(const char *format, ...)
{
	int printed_chars;
	Conversion conversion_list[] = {
		{"c", print_character},
		{"s", print_string},
		{"%", print_percent},
		{"d", print_integer},
		{"i", print_integer},
		{"b", print_binary},
		{"r", print_reversed},
		{"R", rotate_13},
		{"u", print_unsigned_integer},
		{"o", print_octal},
		{"x", print_hexadecimal},
		{"X", print_HEXADECIMAL},
		{NULL, NULL}
	};
	va_list arg_list;

	if (format == NULL)
		return (-1);

	va_start(arg_list, format);
	printed_chars = parse_format(format, conversion_list, arg_list);
	va_end(arg_list);

	return (printed_chars);
}

