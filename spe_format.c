#include "main.h"

#define BUFFER_SIZE 1024

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: Number of characters printed (excluding the null byte).
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	char buffer[BUFFER_SIZE];
	int buf_index = 0;
	int i;
	char *str;

	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (buf_index == BUFFER_SIZE - 1)
		{
			write(1, buffer, buf_index);
			printed_chars += buf_index;
			buf_index = 0;
		}

		if (format[i] != '%')
		{
			buffer[buf_index++] = format[i];
			printed_chars++;
		}
		else
		{
			i++;

			switch (format[i])
			{
				case 'c':
					buffer[buf_index++] = va_arg(args, int);
					printed_chars++;
					break;
				case 's':
					str = va_arg(args, char *);
					while (*str != '\0')
					{
						buffer[buf_index++] = *str;
						printed_chars++;
						str++;
					}
					break;
				case '%':
					buffer[buf_index++] = '%';
					printed_chars++;
					break;
				case 'b':
					printed_chars += print_binary(va_arg(args, unsigned int), buffer, buf_index);
					buf_index = strlen(buffer);
					break;
				case 'S':
					printed_chars += print_custom_string(va_arg(args, char *), buffer, buf_index);
					buf_index = strlen(buffer);
					break;
				case 'r':
					printed_chars += print_reversed_string(va_arg(args, char *), buffer, buf_index);
					buf_index = strlen(buffer);
					break;
				default:
					buffer[buf_index++] = '%';
					buffer[buf_index++] = format[i];
					printed_chars += 2;
					break;
			}
		}
	}

	write(1, buffer, buf_index);
	printed_chars += buf_index;

	va_end(args);

	return printed_chars;
}

/**
 * print_binary - Converts an unsigned int to binary and adds it to the buffer.
 * @n: The unsigned int to convert.
 * @buffer: The buffer to add the converted string.
 * @index: The current index of the buffer.
 *
 * Return: Number of characters added to the buffer.
 */
int print_binary(unsigned int n, char *buffer, int index)
{
	if (n > 1)
		index += print_binary(n / 2, buffer, index);

	buffer[index] = (n % 2) + '0';

	return 1;
}

/**
 * print_custom_string - Prints a string with non-printable characters represented as \x<hex>.
 * @str: The string to print.
 * @buffer: The buffer to add the converted string.
 * @index: The current index of the buffer.
 *
 * Return: Number of characters added to the buffer.
 */
int print_custom_string(char *str, char *buffer, int index)
{
	int count = 0;

	while (*str != '\0')
	{
		if (*str < 32 || *str >= 127)
		{
			buffer[index++] = '\\';
			buffer[index++] = 'x';
			buffer[index++] = (*str / 16) + ((*str / 16) < 10 ? '0' : 'A' - 10);
			buffer[index++] = (*str % 16) + ((*str % 16) < 10 ? '0' : 'A' - 10);
			count += 4;
		}
		else
		{
			buffer[index++] = *str;
			count++;
		}

		str++;
	}

	return count;
}

/**
 * print_reversed_string - Reverses a string and adds it to the buffer.
 * @str: The string to reverse.
 * @buffer: The buffer to add the reversed string.
 * @index: The current index of the buffer.
 *
 * Return: Number of characters added to the buffer.
 */
int print_reversed_string(char *str, char *buffer, int index)
{
	int len = strlen(str);
	int i;

	for (i = len - 1; i >= 0; i--)
	{
		buffer[index++] = str[i];
	}

	return len;
}
