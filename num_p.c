#include "main.h"
/**************************************************
 * pft - prints range of char addresses
 * @x: except address
 * @z: start address
 * @s: stop address
 * Return: number bytes
 ***************************************************/
int pft(char *z, char *s, char *x)
{
int sum = 0;

while (z <= s)
{
if (z != x)
sum += _putchar(*z);
z++;
}
return (sum);
}
/**************************************
 * @pr: string
 * @par: parameters struct
 * pro - prints string in rot13
 * Return: number bytes printed
 **************************************/
int pro(va_list pr, params_t *par)
{
int u, index;
int c = 0;
char Phill[] =
"BCDEFGHIJKLMNOPQRSTUVWXYZA	bcdefghijklmnopqrstuvwxyza";
char *p = va_arg(pr, char *);
(void)par;

u = 0;
index = 0;
while (p[u])
{
if ((p[u] >= 'A' && p[u] <= 'Z')
|| (p[u] >= 'a' && p[u] <= 'z'))
{
index = p[u] - 65;
c += _putchar(Phill[index]);
}
else
c += _putchar(p[u]);
u++;
}
return (c);
}
/**************************************
 * @pr: string
 * @par: parameters struct
 * prr - prints string in reverse
 * Return: number bytes
 **************************************/
int prr(va_list pr, params_t *par)
{
int lh, sum = 0;
char *sr = va_arg(pr, char *);
(void)par;

if (sr)
{
for (lh = 0; *sr; sr++)
lh++;
str--;
for (; lh > 0; lh--, sr--)
sum += _putchar(*sr);
}
return (sum);
}
