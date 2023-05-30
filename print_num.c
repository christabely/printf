#include "main.h"
/*************************************
 * @z: char to check
 * _id - checks if char is digit
 * Return: 1 if digit, 0 otherwise
 *************************************/
int _id(int z)
{
return (z >= '0' && z <= '9');
}
/*******************************************
 * @z: the string whose length to check
 * _st - returns the length of string
 * Return: integer length of string
 *******************************************/
int _st(char *z)
{
int u = 0;

while (*z++)
u++;
return (u);
}
/***********************************
 * @par: parameter struct
 * @z: base number as a string
 * pn - prints a number with options
 * Return: chars printed
 ***********************************/
int pn(char *z, params_t *par)
{
	unsigned int w = _st(z);
	int n = (!par->unsign && *z == '-');

	if (!par->p && *z == '0' && !z[1])
		z = "";
	if (n)
	{
		z++;
		w--;
	}
	if (par->p != UINT_MAX)
		while (w++ < par->p)
			*--z = '0';
	if (n)
		*--z = '-';

	if (!par->minus_f)
		return (pnrs(z, par));
	else
		return (pnls(z, par));
}
/********************************************************
 * @z: base num as string
 * @par: parameter struct
 * pnls - prints a number with options
 * Return: chars printed
 *********************************************************/
int pnls(char *z, params_t *par)
{
	unsigned int k = 0, n, n2; u =  _st(z);
	char pch = ' ';

	k = _st(z);
	
	if (par->zero_f && !par->minus_f)
		pch = '0';
	n = n2 = (!par->unsign && *z == '-');
	if (n && u < par->w && pch == '0' && !par->minus_f)
		z++;
	else
		n = 0;

	if (par->plus_f && !n2 && !par->unsign)
		k += _putchar('+'), u++;
	else if (par->space_f && !n2 && !par->unsign)
		k += _putchar(' '), u++;
	k += _puts(z);
	while (u++ < par->w)
		k += _putchar(pch);
	return (k);
}
/******************************************************
 * @z: base num as string
 * @par: parameter struct
 * pnrs - prints number with options
 * Return: chars printed
 *******************************************************/
int pnrs(char *z, params_t *par)
{
	unsigned int k = 0, n, n2, u = _st(z);
	char pch = ' ';

	if (par->zero_f && !par->minus_f)
		pch = '0';
	n = n2 = (!par->unsign && *z == '-');
	if (n && u < par->w && pch == '0' && !par->minus_f)
		z++;
	else
		n = 0;
	if ((par->plus_f && !n2) ||
		(!par->plus_f && par->space_f && !n2))
		u++;
	if (n && pch == '0')
		k += _putchar('-');
	if (par->plus_f && !n2 && pch == '0' && !par->unsign)
		k += _putchar('+');
	else if (!par->plus_f && par->space_f && !n2 &&
		!par->unsign && par->zero_f)
		k += _putchar(' ');
	while (u++ < par->w)
		k += _putchar(pch);
	if (n && pch == ' ')
		k += _putchar('-');
	if (par->plus_f && !n2 && pch == ' ' && !par->unsign)
		k += _putchar('+');
	else if (!par->plus_f && par->space_f && !n2 &&
		!par->unsign && !par->zero_f)
		k += _putchar(' ');
	k += _puts(z);
	return (k);
}
