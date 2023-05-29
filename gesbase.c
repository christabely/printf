#include "main.h"

/**
 * get_base - Returns the base of the given conversion specifier
 * @format: The conversion specifier
 *
 * Return: The base associated with the specifier.
 */
unsigned int get_base(const char format)
{
	unsigned int base = 10;

	if (format == 'b')
		base = 2;
	else if (format == 'o')
		base = 8;
	else if (format == 'x' || format == 'X' || format == 'p')
		base = 16;

	return (base);
}
