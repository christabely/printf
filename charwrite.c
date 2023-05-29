#include "main.h"
/**
 * _write_character - writes characters
 * @c: character to be printe
 * Return: integer on success
 */
int _write_character(char c)
{
	return (write(1, &c, 1));
}
