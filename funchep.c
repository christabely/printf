#include "main.h"
/*******************************************************
 * p_h - prints unsigned lowercase hex num
 * @ap: argument pointer
 * @params: parameters struct
 * Return: bytes printed
 *******************************************************/
int p_h(va_list ap, params_t *params)
{
	unsigned long h;
	int c = 0;
	char *str;

	if (params->h_m)
		h = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_m)
		h = (unsigned short int)va_arg(ap, unsigned int);
	else
		h = (unsigned int)va_arg(ap, unsigned int);

	str = convert(h, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'x';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += pn(str, params));
}
/************************************************
 * po - prints unsigned octal numbers
 * @ap: the argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 ************************************************/
int po(va_list ap, params_t *params)
{
	unsigned long k;
	char *str;
	int c = 0;

	if (params->h_modifier)
		k = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_m)
		k = (unsigned short int)va_arg(ap, unsigned int);
	else
		k = (unsigned int)va_arg(ap, unsigned int);
	str = convert(k, 8, CONVERT_UNSIGNED, params);

	if (params->hashtag_f && k)
		*--str = '0';
	params->unsign = 1;
	return (c += p_n(str, params));
}
/*********************************************************
 * @ap: argument pointer
 * @params: parameters struct
 * p_H - prints unsigned hex numbers in uppercase
 * Return: bytes printed
 *********************************************************/
int p_H(va_list ap, params_t *params)
{
	unsigned long h;
	int c = 0;
	char *str;

	if (params->l_m)
		h = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_m)
		h = (unsigned short int)va_arg(ap, unsigned int);
	else
		h = (unsigned int)va_arg(ap, unsigned int);

	str = convert(h, 16, CONVERT_UNSIGNED, params);
	if (params->hashtag_flag && l)
	{
		*--str = 'X';
		*--str = '0';
	}
	params->unsign = 1;
	return (c += pn(str, params));
}
/**********************************************
 * print_binary - prints unsigned binary number
 * @ap: the argument pointer
 * @params: the parameters struct
 *
 * Return: bytes printed
 **********************************************/
int print_binary(va_list ap, params_t *params)
{
	unsigned int u = va_arg(ap, unsigned int);
	char *str = convert(n, 2, CONVERT_UNSIGNED, params);
	int q = 0;

	if (params->hashtag_f && u)
		*--str = '0';
	params->unsign = 1;
	return (q += p_n(str, params));
}
