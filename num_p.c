#include "main.h"
/**
 * pft - prints range of char addresses
 * @exit: exit address
 * @start: start address
 * @stop: stop address
 * Return: number bytes
 */
int pft(char *start, char *stop, char *exit)
{
int sum = 0;

while (start <= stop)
{
if (start != exit)
sum += _putchar(*start);
start++;
}
return (sum);
}
/**
 * pro - prints string in rot13
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number bytes printed
 */
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
/**
 * prr - prints string in reverse
 * @pr: argument pointer
 * @par: parameters struct
 * Return: number bytes
 */
int prr(va_list pr, params_t *par)
{
int lh, sum = 0;
char *z = va_arg(pr, char *);
(void)par;

if (z)
{
for (lh = 0; *z; z++)
lh++;
z--;
for (; lh > 0; lh--, z--)
sum += _putchar(*z);
}
return (sum);
}
