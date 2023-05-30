#include "main.h"
/**
 * con - converter function, a clone of itoa
 * @b: number
 * @bs: base
 * @fs: argument flags
 * @par: parameters struct
 *
 * Return: string
 */
char *con(long int b, int bs, int fs, params_t *par)
{
static char *array;
static char buffer[50];
char sign = 0;
char *tr;
unsigned long h = b;
(void)par;

if (!(fs & CON_UNSIGNED) && b < 0)
{
h = -b;
sign = '-';

}
array = fs & CON_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
tr = &buffer[49];
*tr = '\0';

do	{
*--tr = array[h % bs];
h /= bs;
} while (h != 0);

if (sign)
*--tr = sign;
return (tr);
}
/**
 * p_u - prints unsigned integer numbers
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 */
int p_u(va_list pr, params_t *par)
{
unsigned long h;

if (par->h_m)
h = (unsigned long)va_arg(pr, unsigned long);
else if (par->h_m)
h = (unsigned short int)va_arg(pr, unsigned int);
else
h = (unsigned int)va_arg(pr, unsigned int);
par->unsign = 1;
return (pn(con(h, 10, CON_UNSIGNED, par), par));
}
/**
 * p_a - prints address
 * @pr: argument pointer
 * @par: parameters struct
 * Return: bytes printed
 */
int p_a(va_list pr, params_t *par)
{
	unsigned long int h = va_arg(pr, unsigned long int);
	char *z;

	if (!h)
		return (_puts("(nil)"));

	z = con(h, 16, CON_UNSIGNED | CON_LOWERCASE, par);
	*--z = 'x';
	*--z = '0';
	return (pn(z, par));
}
