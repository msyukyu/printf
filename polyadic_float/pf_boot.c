/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_boot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:36:10 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/19 12:55:41 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned char	shift_left(PFMNG *mng)
{
	PF				*cur;

	if ((mng->d_e->value & 1) && !init_pf((PFBASE / 10) * 5, mng->d_e, NULL))
		return (0);
	cur = mng->d_e;
	while (cur)
	{
		cur = cur->left;
	}
}

void			decode_fraction(t_dbl *dbl, PFMNG *mng, PFMNG *shadow)
{
	unsigned int	left_offset;

	shadow->d_s->value = (PFBASE / 10) * 5;
	left_offset = 0;
	while (++left_offset < dbl->fraction.left_offset)
	{
		shift_left(shadow);
	}
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
}
