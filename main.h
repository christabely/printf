#ifndef PRINTF_UTILS_H
#define PRINTF_UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * struct conversion - function struct
 * @symbol: symbol
 * @function: function
 */
struct conversion
{
    char *symbol;
    int (*function)(va_list);
};
typedef struct conversion Conversion;

/* Main functions */
int parse_format(const char *format, Conversion conversion_list[], va_list arg_list);
int my_printf(const char *format, ...);
int write_character(char);
int print_character(va_list);
int print_string(va_list);
int print_percent(va_list);
int print_integer(va_list);
int print_number(va_list);
int print_binary(va_list);
int print_reversed(va_list);
int rotate_13(va_list);
int print_unsigned_integer(va_list);
int print_octal(va_list);
int print_hexadecimal(va_list);
int print_HEXADECIMAL(va_list);

/* Helper functions */
unsigned int get_base_length(unsigned int num, int base);
char *reverse_string(char *);
void write_base_string(char *str);
char *_memcpy(char *destination, char *source, unsigned int n);
int print_unsigned_number(unsigned int);

#endif

