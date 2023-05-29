#include "main.h"

/**************************************************
 * p_f_t - prints a range of char addresses
 * @except: except address
 * @start: starting address
 * @stop: stopping address
 * Return: number bytes
 ***************************************************/
int p_f_t(char *start, char *stop, char *except)
{
	int sum = 0;

	while (start <= stop)
	{
		if (start != except)
			sum += _putchar(*start);
		start++;
	}
	return (sum);
}
/**************************************
 * @ap: string
 * @params: the parameters struct
 * pro - prints string in rot13
 * Return: number bytes printed
 **************************************/
int pro(va_list ap, params_t *params)
{
	int m, d;
	int c = 0;
	char tfs[] =
		"NOPQRSTUVWXYZABCDEFGHIJKLM      nopqrstuvwxyzabcdefghijklm";
	char *a = va_arg(ap, char *);
	(void)params;

	m = 0;
	d = 0;
	while (a[m])
	{
		if ((a[m] >= 'A' && a[m] <= 'Z')
		    || (a[m] >= 'a' && a[m] <= 'z'))
		{
			d = a[m] - 65;
			c += _putchar(tfs[d]);
		}
		else
			c += _putchar(a[m]);
		m++;
	}
	return (c);
}
/**************************************
 * @ap: string
 * @params: parameters struct
 * pr - prints string in reverse
 * Return: number bytes
 **************************************/
int pr(va_list ap, params_t *params)
{
	int len, sum = 0;
	char *str = va_arg(ap, char *);
	(void)params;

	if (str)
	{
		for (len = 0; *str; str++)
			len++;
		str--;
		for (; len > 0; len--, str--)
			sum += _putchar(*str);
	}
	return (sum);
}
