#include "main.h"
/************************************************************
 * get_precision - gets the precision from the format string
 * @l: format string
 * @ap: argument pointer
 * @params: parameters struct 
 * Return: new pointer
 *************************************************************/
char *gp(char *l, params_t *params, va_list ap)
{
	int u = 0;

	if (*l == '.')
	{
		l++;
		if (*l == '*')
		{
			u = va_arg(ap, int);
			l++;
		}
		else
		{
			while (_isdigit(*l))
			{
				u = u * 10 + (*l - '0');
				l++;
			}
		}
		params->p = u;
	}
	return (l);
}
