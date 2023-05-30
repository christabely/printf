#include "main.h"

/**************************************************
 * convert - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 * @params: paramater struct
 * Return: string
 ***************************************************/
char *convert(long int num, int base, int flags, params_t *params)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;
	(void)params;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}
/*************************************************
 * p_u - prints unsigned integer numbers
 * @ap: argument pointer
 * @params: the parameters struct
 * Return: bytes printed
 *************************************************/
int p_u(va_list ap, params_t *params)
{
	unsigned long h;

	if (params->h_m)
		h = (unsigned long)va_arg(ap, unsigned long);
	else if (params->h_modifier)
		h = (unsigned short int)va_arg(ap, unsigned int);
	else
		h = (unsigned int)va_arg(ap, unsigned int);
	params->unsign = 1;
	return (p_n(convert(l, 10, CONVERT_UNSIGNED, params), params));
}
/****************************
 * p_a - prints address
 * @ap: argument pointer
 * @params: parameters struct
 * Return: bytes printed
 ****************************/
int p_a(va_list ap, params_t *params)
{
	unsigned long int f = va_arg(ap, unsigned long int);
	char *str;

	if (!f)
		return (_puts("(nil)"));

	str = convert(f, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, params);
	*--str = 'x';
	*--str = '0';
	return (p_n(str, params));
}
