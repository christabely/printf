#include "main.h"
/**
 * pc - prints character
 * @par: parameters struct
 *
 * Return: number of chars printed
 */
int pc(va_list pr, params_t *par)
{
char pch = ' ';
unsigned int k = 1, sum = 0, nv = va_arg(pr, int);
	
if (par->minus_f)
sum += _putchar(nv);
while (k++ < par->w)
sum += _putchar(pch);
if (!par->minus_f)
sum += _putchar(nv);
return (sum);
}
/**
 * pp - prints string
 * @par: parameters struct
 *
 * Return: number of chars printed
 */
int pp(va_list pr, params_t *par)
{
(void)pr;
(void)par;
return (_putchar('%'));
}
/**
 * pi - prints integer
 * @par: parameters struct
 *
 * Return: number of chars printed
 */
int pi(va_list pr, params_t *par)
{
long l;

if (par->l_m)
l = va_arg(pr, long);
else if (par->h_m)
l = (short int)va_arg(pr, int);
else
l = (int)va_arg(pr, int);
return (pn(con(l, 10, 0, par), par));
}
/**
 * p_S - custom format specifier
 * @par: parameters struct
 *
 * Return: number of chars printed
 */
int p_S(va_list pr, params_t *par)
{
char *z = va_arg(pr, char *);
char *x;
int sum = 0;

if ((int)(!z))
return (_puts(NULL_STRING));
for (; *z; z++)
{
if ((*z > 0 && *z < 32) || *z >= 127)
{
sum += _putchar('\\');
sum += _putchar('x');
x = con(*z, 16, 0, par);
if (!x[1])
sum += _putchar('0');
sum += _puts(x);
}
else
{
sum += _putchar(*z);
}
}
return (sum);
}
/**
 * pst - prints string
 * @par: parameters struct
 * Return: number of chars printed
 */
int pst(va_list pr, params_t *par)
{
char *z = va_arg(pr, char *), pch = ' ';
unsigned int k = 0, sum = 0, u = 0, y;

(void)par;
switch ((int)(!z))
case 1:
z = NULL_STRING;

y = k = _st(z);
if (par->p < k)
y = k = par->p;

if (par->minus_f)
{
if (par->p != UINT_MAX)
for (u = 0; u < k; u++)
sum += _putchar(*z++);
else
sum += _puts(z);
}
while (y++ < par->w)
sum += _putchar(pch);
if (!par->minus_f)
{
if (par->p != UINT_MAX)
for (u= 0; u < k; u++)
sum += _putchar(*z++);
else
sum += _puts(z);
}
return (sum);
}
