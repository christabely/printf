#include "main.h"
/*************************************************
 * @ap: argument pointer
 * init_params - clears struct fields and reset buf
 * @params: parameters struct
 * Return: void
 *************************************************/
void init_params(params_t *params, va_list ap)
{
	params->unsign = 0;

	params->hashtag_f = 0;
	params->zero_f = 0;
	params->plus_f = 0;
	params->minus_f = 0;
	params->space_f = 0;

	params->precision = UINT_MAX;
	params->width = 0;

	params->l_m = 0;
	params->h_m = 0;
	(void)ap;
}
