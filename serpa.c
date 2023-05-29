#include "main.h"
/***************************************
 * @s: format string
 * get_specifier - finds the format of function
 * Return: number of bytes
 ***************************************/
int (*get_specifier(char *s))(va_list ap, params_t *params)
{
	specifier_t specifiers[] = {
		
		{"d", print_int},
		{"i", print_int},
		{"s", print_string},
		{"r", print_rev},
		{"b", print_binary},
		{"S", print_S},
		{"o", print_octal},
		{"R", print_rot13},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"%", print_percent},
		{"c", print_char},
		{"u", print_unsigned},
		{NULL, NULL}
	};
	int i;

	for (i = 0; specifiers[i].specifier; i++)
	{
    		if (*s == specifiers[i].specifier[0])
    		{
        		return specifiers[i].f;
    		}
	}
	
	return (NULL);
}
/****************************************
 * gpf - finds format function
 * @ap: argument pointer
 * @params: the parameters struct
 * @s: the format string
 * Return: number of bytes
 ****************************************/
int gpf(char *s, va_list ap, params_t *params)
{
	int (*f)(va_list, params_t *) = get_specifier(s);

	if (f)
		return (f(ap, params));
	return (0);
}
/********************************
 * @s: format string
 * @params:parameters struct
 * gf - finds flag function
 * Return: if flag was valid
 *******************************/
int gf(char *s, params_t *params)
{
	int a = 0;

	switch (*s)
	{
		case '+':
			a = params->plus_f = 1;
			break;
		case ' ':
			a = params->space_f = 1;
			break;
		case '#':
			a = params->hashtag_f = 1;
			break;
		case '-':
			a = params->minus_f = 1;
			break;
		case '0':
			a = params->zero_f = 1;
			break;
	}
	return (a);
}
/*************************************
 * gm - getsmodifier function
 * @params: the parameters struct
 * @s: the format string
 * Return: if modifier was valid
 ************************************/
int gm(char *s, params_t *params)
{
	int m = 0;

	switch (*s)
	{
	case 'h':
		m = params->h_m = 1;
		break;
	case 'l':
		m = params->l_m = 1;
		break;
	}
	return (m);
}
/***************************************************
 * @params: parameters struct
 * gw - gets width from format string
 * @ap: argument pointer
 * @s: format string
 * Return: new pointer
 ***************************************************/
char *gw(char *s, params_t *params, va_list ap)
{
	int r = 0;

	if (*s == '*')
	{
		r = va_arg(ap, int);
		s++;
	}
	else
	{
		while (_isdigit(*s))
			r = r * 10 + (*s++ - '0');
	}
	params->w = r;
	return (s);
}
