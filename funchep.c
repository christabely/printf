#include "main.h"
/**
 * p_h - prints unsigned lowercase hex num
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 * On error, -1 is returned, and error is set appropriately.
 */
int p_h(va_list pr, params_t *par)
{
	unsigned long h;
	int c = 0;
	char *z;

	if (par->l_m)
		h = (unsigned long)va_arg(pr, unsigned long);
	else if (par->h_m)
		h = (unsigned short int)va_arg(pr, unsigned int);
	else
		h = (unsigned int)va_arg(pr, unsigned int);

	z = con(h, 16, CON_UNSIGNED | CON_LOWERCASE, par);
	if (par->hashtag_f && h)
	{
		*--z = 'x';
		*--z = '0';
	}
	par->unsign = 1;
	return (c += pn(z, par));
}
/**
 * po - prints unsigned octal num
 * @pr: argument pointer
 * @par: parameters struct
 *
 * Return: bytes printed
 */
int po(va_list pr, params_t *par)
{
	unsigned long h;
	char *z;
	int c = 0;

	if (par->l_m)
		h = (unsigned long)va_arg(pr, unsigned long);
	else if (par->h_m)
		h = (unsigned short int)va_arg(pr, unsigned int);
	else
		h = (unsigned int)va_arg(pr, unsigned int);
	z = con(h, 8, CON_UNSIGNED, par);

	if (par->hashtag_f && h)
		*--z = '0';
	par->unsign = 1;
	return (c += pn(z, par));
}
/**
 * p_H - prints unsigned hex numbers in uppercase
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 */
int p_H(va_list pr, params_t *par)
{
	unsigned long h;
	int c = 0;
	char *z;

	if (par->l_m)
		h = (unsigned long)va_arg(pr, unsigned long);
	else if (par->h_m)
		h = (unsigned short int)va_arg(pr, unsigned int);
	else
		h = (unsigned int)va_arg(pr, unsigned int);

	z = con(h, 16, CON_UNSIGNED, par);
	if (par->hashtag_f && h)
	{
		*--z = 'X';
		*--z = '0';
	}
	par->unsign = 1;
	return (c += pn(z, par));
}
/**
 * pb - prints unsigned binary number
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 */
int pb(va_list pr, params_t *par)
{
	unsigned int h = va_arg(pr, unsigned int);
	char *z = con(h, 2, CON_UNSIGNED, par);
	int c = 0;

	if (par->hashtag_f && h)
		*--z = '0';
	par->unsign = 1;
	return (c += pn(z, par));
}
