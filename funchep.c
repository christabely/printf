#include "main.h"

/**
 * funchep - Returns a function pointer based on the conversion specifier
 * @format: The conversion specifier
 *
 * Return: Pointer to the corresponding conversion function, or NULL if invalid.
 */
int (*funchep(const char *format))(va_list, int *)
{
	int i;
	converter_t converters[] = {
		{'c', print_char},
		{'s', print_string},
		{'%', print_percent},
		{'d', print_decimal},
		{'i', print_decimal},
		{'b', print_binary},
		{'u', print_unsigned},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex_upper},
		{'S', print_string_custom},
		{'p', print_pointer},
		{'r', print_reverse},
		{'R', print_rot13},
		{'\0', NULL}
	};

	for (i = 0; converters[i].specifier != '\0'; i++)
	{
		if (converters[i].specifier == *format)
			return (converters[i].printer);
	}

	return (NULL);
}
