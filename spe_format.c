#include "main.h"
/************************************************************
 * get_precision - gets the precision from the format string
 * @ap: the argument pointer
 * @params: the parameters struct 
 * @p: the format string
 *
 * Return: new pointer
 *************************************************************/
char *get_precision(char *p, params_t *params, va_list ap)
{
	int d = 0;

	if (*p == '.')
	{
		p++;
		if (*p == '*')
		{
			d = va_arg(ap, int);
			p++;
		}
		else
		{
			while (_isdigit(*p))
			{
				d = d * 10 + (*p - '0');
				p++;
			}
		}
		params->precision = d;
	}
	return (p);
}
