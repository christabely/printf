#include "main.h"

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
params->p = u;
return (z);
}
/************************************************************
 * gp - gets precision from format string
 * @z: format string
 * @pr: pointer argument 
 * @par: parameters struct 
 * Return: new pointer
 ************************************************************/
