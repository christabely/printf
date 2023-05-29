#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>

int _printf(const char *format, ...);
int _putchar(char c);
int charwrite(char c, int *count);
int (*funchep(const char *format))(va_list, int *);
unsigned int get_base(const char format);
int print_char(va_list args, int *count);
int print_string(va_list args, int *count);
int print_percent(va_list args, int *count);
int print_decimal(va_list args, int *count);
int print_unsigned(va_list args, int *count);
int print_binary(va_list args, int *count);
int print_octal(va_list args, int *count);
int print_hex(va_list args, int *count);
int print_hex_upper(va_list args, int *count);
int print_string_custom(va_list args, int *count);
int print_pointer(va_list args, int *count);
int print_reverse(va_list args, int *count);
int print_rot13(va_list args, int *count);

/**
 * struct converter - Struct for conversion specifiers and their functions
 * @specifier: The conversion specifier
 * @printer: Pointer to the conversion function
 */
typedef struct converter
{
	char specifier;
	int (*printer)(va_list, int *);
} converter_t;

#endif /* MAIN_H */
