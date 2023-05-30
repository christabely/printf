#include "main.h"
/**********************************
 * _printf - prints anything
 * @format: the format string
 * Return: number of bytes printed
 **********************************/
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list pr;
	char *p, *star;
	params_t par = PARAMS_INIT;

	va_start(pr, format);

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		itp(&par, pr);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (gf(p, &par))
		{
			p++;
		}
		p = gw(p, &par, pr);
		p = gp(p, &par, pr);
		if (gm(p, &par))
			p++;
		if (!gs(p))
			sum += pft(start, p,
				par.l_m || par.h_m ? p - 1 : 0);
		else
			sum += gpf(p, pr, &par);
	}
	_putchar(BUF_FLUSH);
	va_end(pr);
	return (sum);
}
