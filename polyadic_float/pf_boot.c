/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_boot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:36:10 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/19 13:16:42 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

PF				*add_right(ULL value, PFMNG *mng)
{
	if (!init_pf(PFBASE, mng->d_e, NULL))
		return (NULL);
	mng->d_e = mng->d_e->right;
	return (mng->d_e);
}

unsigned char	shift_right(PFMNG *mng)
{
	PF				*cur;

	if ((mng->d_e->value & 1) && !add_right(PFBASE, mng))
		return (0);
	cur = mng->d_e;
	while (cur)
	{
		if (cur->value & 1)
			cur->right->inc = PFBASE >> 1;
		cur->value = cur->value >> 1;
		cur = cur->left;
	}
	cur = mng->i_e->right;
	while (cur)
	{
		cur->value += cur->inc;
		cur->inc = 0;
		cur = cur->right;
	}
	return (1);
}

unsigned char	decode_fraction(t_dbl *dbl, PFMNG *mng, PFMNG *shadow)
{
	unsigned int	left_offset;

	shadow->d_s->value = PFBASE >> 1;
	left_offset = 0;
	while (++left_offset < dbl->fraction.left_offset)
	{
		shift_right(shadow);
	}
	printf("%llu\n", shadow->d_s->value);
	return (1);
}

PFMNG			*pf_boot(long double in)
{
	t_dbl			*dbl;
	PFMNG			*mng;
	PFMNG			*shadow;

	if (!(dbl = extract_ldouble_infos(in)))
		return (NULL);
	if (!(mng = init_pfmng(dbl)) || !(shadow = init_pfmng(dbl)))
	{
		free(mng);
		free(dbl);
		return (NULL);
	}
	mng->i_s->value = dbl->normalized;
	decode_fraction(dbl, mng, shadow);
	return (mng);
}
