#include "main.h"

char *gp(char *l, params_t *params, va_list ap)
{
int u = 0;

if (*l != '.')
return (l);
l++;
if (*l == '*')
{
u = va_arg(ap, int);
l++;
}
else
{
while (_id(*l))
u = u * 10 + (*l++ - '0');
}
params->p = u;
return (l);
}
/************************************************************
 * get_precision - gets the precision from the format string
 * @l: format string
 * @ap: argument pointer
 * @params: parameters struct 
 * Return: new pointer
 ************************************************************/
