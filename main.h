#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1
#define FIELD_BUF_SIZE 50
#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/**
 * struct parameters - parameters struct
 * @unsign: flag if unsigned value
 * @plus_f: on if plus_flag specified
 * @space_f: on if hashtag_flag specified
 * @hashtag_f: on if _flag specified
 * @zero_f: on if _flag specified
 * @minus_f: on if _flag specified
 * @w: field width specified
 * @p: field precision specified
 * @h_m: on if h_m is specified
 * @l_m: on if l_m is specified
 *
 */
typedef struct parameters
{
	unsigned int unsign : 1;
	unsigned int plus_f : 1;
	unsigned int space_f : 1;
	unsigned int hashtag_f : 1;
	unsigned int zero_f : 1;
	unsigned int minus_f : 1;
	unsigned int h_modifier : 1;
	unsigned int l_modifier : 1;
	unsigned int w;
	unsigned int p;
} params_t;

/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
 */
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

int _puts(char *str);
int _putchar(int c);
char *gw(char *s, params_t *params, va_list ap)
int p_h(va_list ap, params_t *params)
int p_H(va_list ap, params_t *params)
int print_binary(va_list ap, params_t *params);
int po(va_list ap, params_t *params)
char *convert(long int num, int base, int flags, params_t *params);
int p_u(va_list ap, params_t *params)
int p_a(va_list ap, params_t *params)
int (*get_specifier(char *s))(va_list ap, params_t *params);
int gpf(char *s, va_list ap, params_t *params)
int print_char(va_list ap, params_t *params);
int pi(va_list ap, params_t *params)
int pst(va_list ap, params_t *params)
int pp(va_list ap, params_t *params)
int p_S(va_list ap, params_t *params)
int gf(char *s, params_t *params)
int gm(char *s, params_t *params)
int pft(char *start, char *stop, char *except)
int pr(va_list ap, params_t *params)
int pro(va_list ap, params_t *params)
/* print_number.c module */
int _isdigit(int c);
int _strlen(char *s);
int pn(char *str, params_t *params)
int pnrs(char *str, params_t *params)
int pnls(char *str, params_t *params)
void init_params(params_t *params, va_list ap);
char *gp(char *l, params_t *params, va_list ap)
int _printf(const char *format, ...);

#endif
