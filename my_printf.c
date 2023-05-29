#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: The format string
 *
 * Return: The number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;
	int (*printer)(va_list, int *);

	if (format == NULL)
		return (-1);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			printer = funchep(&format[i + 1]);
			if (printer != NULL)
			{
				count += printer(args, &count);
				i++;
			}
			else
			{
				count += charwrite('%', &count);
			}
		}
		else
		{
			count += charwrite(format[i], &count);
		}
		i++;
	}
	va_end(args);

	return (count);
}
