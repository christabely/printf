#include "main.h"
/*************************************
 * @c: char to check
 * _isdigit - checks if char is digit
 * Return: 1 if digit, 0 otherwise
 *************************************/
int _id(int c)
{
	return (c >= '0' && c <= '9');
}
/*******************************************
 * @s: the string whose length to check
 * _st - returns the length of string
 * Return: integer length of string
 *******************************************/
int _st(char *s)
{
	int n = 0;

	while (*s++)
		n++;
	return (n);
}
/***********************************
 * @params: parameter struct
 * @str: base number as a string
 * pn - prints a number with options
 * Return: chars printed
 ***********************************/
int pn(char *str, params_t *params)
{
	unsigned int i = _strlen(str);
	int neg = (!params->unsign && *str == '-');

	if (!params->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (params->precision != UINT_MAX)
		while (i++ < params->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!params->minus_f)
		return (pn(str, params));
	else
		return (pn(str, params));
}
/********************************************************
 * @str: base num as string
 * @params: parameter struct
 * pnls - prints a number with options
 *
 * Return: chars printed
 *********************************************************/
int pnls(char *str, params_t *params)
{
	unsigned int k = 0, neg, neg2;
	unsigned int w;
	char pad_char = ' ';

	w = _strlen(str);

	if (params->zero_flag && !params->minus_flag)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && w < params->width && pad_char == '0' && !params->minus_flag)
		str++;
	else
		neg = 0;

	if (params->plus_flag && !neg2 && !params->unsign)
		k += _putchar('+'), w++;
	else if (params->space_flag && !neg2 && !params->unsign)
		k += _putchar(' '), w++;
	k += _puts(str);

	for (; w < params->width; w++)
		k += _putchar(pad_char);

	return (k);
}
/******************************************************
 * @str: base num as string
 * @params: parameter struct
 * pnrs - prints number with options
 * Return: chars printed
 *******************************************************/
int pnrs(char *str, params_t *params)
{
	unsigned int v = 0, neg, neg2, g = _strlen(str);
	char pad_char = ' ';

	if (params->zero_f && !params->minus_f)
		pad_char = '0';
	neg = neg2 = (!params->unsign && *str == '-');
	if (neg && g < params->width && pad_char == '0' && !params->minus_f)
		str++;
	else
		neg = 0;
	if ((params->plus_f && !neg2) ||
		(!params->plus_f && params->space_f && !neg2))
		g++;
	if (neg && pad_char == '0')
		v += _putchar('-');
	if (params->plus_f && !neg2 && pad_char == '0' && !params->unsign)
		v += _putchar('+');
	else if (!params->plus_f && params->space_f && !neg2 &&
		!params->unsign && params->zero_f)
		v += _putchar(' ');
	while (g++ < params->width)
		v += _putchar(pad_char);
	if (neg && pad_char == ' ')
		v += _putchar('-');
	if (params->plus_f && !neg2 && pad_char == ' ' && !params->unsign)
		v += _putchar('+');
	else if (!params->plus_f && params->space_f && !neg2 &&
		!params->unsign && !params->zero_f)
		v += _putchar(' ');
	v += _puts(str);
	return (v);
}
