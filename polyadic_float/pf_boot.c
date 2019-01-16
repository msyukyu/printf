/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_boot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:36:10 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/16 17:03:40 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			increment_shadow(PFMNG *mng, PF *cur)
{

}

unsigned char	shift_shadow(PFMNG *mng, PF *cur)
{
	if (cur->right)
		shift_shadow(mng, cur->right);
	if (cur->shadow & 1)
	{
		if (cur->right)
			cur->right->inc_shadow += (PFBASE / 10) * 5;
		else
		{
			if (!add_right_shadow((PFBASE / 10) * 5, mng))
				return (0);
		}

	}
	cur->shadow = cur->shadow >> 1;
	return (1);
}

void			decode_fraction(t_dbl *dbl, PFMNG *mng)
{
	unsigned int	left_offset;

	mng->d_s->shadow = (PFBASE / 10) * 5;
	left_offset = 0;
	while (++left_offset < dbl->fraction.left_offset)
	{
		shift_shadow(mng, mng->d_s);
		increment_shadow(mng, mng->d_e);
	}
}

PFMNG			*pf_boot(long double in)
{
	t_dbl			*dbl;
	PFMNG			*mng;

	if (!(dbl = extract_ldouble_infos(in)))
		return (NULL);
	if (!(mng = init_pfmng(dbl)))
	{
		free(dbl);
		return (NULL);
	}
	mng->i_s->value = dbl->normalized;
	decode_fraction(dbl, mng);
}
