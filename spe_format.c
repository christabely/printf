#include "main.h"
/**
 * gp - gets precision from format string
 * @z: format string
 * @par: parameter
 * @pr: argument pointer
 *
 * Return: new pointer
 */
char *gp(char *z, params_t *par, va_list pr)
{
int u = 0;

if (*z != '.')
return (z);
z++;
if (*z == '*')
{
u = va_arg(pr, int);
z++;
}
else
{
while (_id(*z))
u = u * 10 + (*z++ - '0');
}
par->p = u;
return (z);
}
