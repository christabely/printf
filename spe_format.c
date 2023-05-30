#include "main.h"

char *gp(char *l, params_t *par, va_list pr)
{
int u = 0;

if (*l != '.')
return (l);
l++;
if (*l == '*')
{
u = va_arg(pr, int);
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
 * gp - gets precision from format string
 * @l: format string
 * @pr: pointer argument 
 * @par: parameters struct 
 * Return: new pointer
 ************************************************************/
