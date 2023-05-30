#include "main.h"
/***************************************
 * @z: format string
 * gs - finds the format of function
 * Return: number of bytes
 ***************************************/
int (*gs(char *z))(va_list pr, params_t *par)
{
specifier_t speci[] = {

{"d", pi},
{"i", pi},
{"s", pst},
{"r", pr},
{"b", pb},
{"S", p_S},
{"o", po},
{"R", pro},
{"x", p_h},
{"X", p_H},
{"%", pp},
{"p", p_a},
{"c", pc},
{"u", p_u},
{NULL, NULL}
};
int u;

for (u = 0; speci[u].speci; u++)
{
if (*z == speci[u].speci[0])
{
return (speci[u].f);
}
}	
return (NULL);
}
/****************************************
 * gpf - finds format function
 * @pr: pointer argument
 * @par: parameters struct
 * @z: the format string
 * Return: number of bytes
 ****************************************/
int gpf(char *z, va_list ap, params_t *params)
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
