#include "main.h"

void itp(params_t *par, va_list pr)
{
par->p = UINT_MAX;
par->w = 0;
par->unsign = 0;
par->hashtag_f = 0;
par->zero_f = 0;
par->plus_f = 0;
par->minus_f = 0;
par->space_f = 0;
params->l_m = 0;
params->h_m = 0;
(void)pr;
}
/*************************************************
 * @pr: argument pointer
 * itp - clears struct fields and reset buf
 * @par: parameters struct
 * Return: void
 *************************************************/
