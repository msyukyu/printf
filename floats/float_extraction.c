/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_extraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:54:42 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/16 13:50:03 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_dbl			*extract_ldouble_infos(long double in)
{
	unsigned char	*bits;
	t_dbl			*dbl;

	bits = store_ldouble_bits(in);
	if (!bits)
		return (NULL);
	dbl = (t_dbl*)malloc(sizeof(t_dbl));
	if (!dbl)
		return (NULL);
	dbl->sign = extract_float_sign(bits, 10);
	dbl->exponent = extract_float_exponent(15, 1, bits, 10);
	dbl->normalized = extract_ldouble_normalized(16, bits, 10);
	dbl->fraction = extract_float_fraction(63, 17, bits, 10);
	free(bits);
	return (dbl);
}

t_dbl			*extract_double_infos(double in)
{
	unsigned char	*bits;
	t_dbl			*dbl;
	int				constant;

	bits = store_double_bits(in);
	if(!bits)
		return (NULL);
	dbl = (t_dbl*)malloc(sizeof(t_dbl));
	if (!dbl)
		return (NULL);
	dbl->sign = extract_float_sign(bits, sizeof(double));
	dbl->exponent = extract_float_exponent(11, 1, bits, sizeof(double));
	constant = (int)(((unsigned int)1) << (10));
	dbl->normalized = (dbl->exponent == constant ||
			dbl->exponent == -constant + 1) ? 0 : 1;
	dbl->fraction = extract_float_fraction(52, 12, bits, sizeof(double));
	free(bits);
	return (dbl);
}
