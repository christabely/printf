#include "main.h"
/*********************************
 * @ap: argument pointer
 * @params: parameters struct
 * pc - prints character
 * Return: number chars printed
 *********************************/
int pc(va_list ap, params_t *params)
{
	char p_c = ' ';
	unsigned int p = 1, sum = 0, nv = va_arg(ap, int);

	if (params->minus_f)
		sum += _putchar(nv);
	while (p++ < params->width)
		sum += _putchar(p_c);
	if (!params->minus_f)
		sum += _putchar(nv);
	return (sum);
}
/********************************
 * @ap: argument pointer
 * @params: the parameters struct
 * pp - prints string
 * Return: number chars printed
 ********************************/
int pp(va_list ap, params_t *params)
{
	(void)ap;
	(void)params;
	return (_putchar('%'));
}
/*******************************
 * @params: parameters struct
 * pi - prints integer
 * @ap: argument pointer
 * Return: number chars printed
 ********************************/
int pi(va_list ap, params_t *params)
{
	long j;

	if (params->l_modifier)
		j = va_arg(ap, long);
	else if (params->h_modifier)
		j = (short int)va_arg(ap, int);
	else
		j = (int)va_arg(ap, int);
	return (print_number(convert(j, 10, 0, params), params));
}
/*********************************
 * @params: the parameters struct
 * p_S - custom format specifier
 * @ap: argument pointer
 * Return: number chars printed
 ********************************/
int p_S(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *);
	char *hex;
	int sum = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			sum += _putchar('\\');
			sum += _putchar('x');
			hex = convert(*str, 16, 0, params);
			if (!hex[1])
				sum += _putchar('0');
			sum += _puts(hex);
		}
		else
		{
			sum += _putchar(*str);
		}
	}
	return (sum);
}
/*********************************
 * @params: parameters struct
 * pst - prints string
 * @ap: argument pointer
 * Return: number chars printed
 *********************************/
int pst(va_list ap, params_t *params)
{
	char *str = va_arg(ap, char *), p_c = ' ';
	unsigned int p = 0, sum = 0, h = 0, y;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	y = p = _strlen(str);
	if (params->precision < p)
		y = p = params->precision;

	if (params->minus_flag)
	{
		if (params->precision != UINT_MAX)
			for (h = 0; h < p; h++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (y++ < params->width)
		sum += _putchar(p_c);
	if (!params->minus_f)
	{
		if (params->precision != UINT_MAX)
			for (h = 0; h < p; h++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	return (sum);
}
