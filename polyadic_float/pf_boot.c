/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_boot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:36:10 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/19 18:07:46 by dabeloos         ###   ########.fr       */
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

PF				*add_left(ULL value, PFMNG *mng)
{
	if (!init_pf(0, NULL, mng->i_e))
		return (NULL);
	mng->i_e = mng->i_e->left;
	return (mng->i_e);
}

unsigned char	shift_right(PFMNG *mng)
{
	PF				*cur;

	if ((mng->d_e->value & 1) && !add_right(0, mng))
		return (0);
	cur = mng->d_e;
	while (cur)
	{
		if (cur->value & 1)
			cur->right->inc = PFBASE >> 1;
		cur->value = cur->value >> 1;
		cur = cur->left;
	}
	cur = mng->d_e;
	while (cur)
	{
		cur->value += cur->inc;
		while (cur->value >= PFBASE)
		{
			cur->value -= PFBASE;
			cur->left->inc += 1;
		}
		cur->inc = 0;
		cur = cur->left; //debordement bloc
	}
	return (1);
}

unsigned char	shift_left(PFMNG *mng)
{
	PF				*cur;

	if ((mng->i_e->value & 1) && !add_left(0, mng))
		return (0);
	cur = mng->i_e;
	while (cur)
	{
		cur->value = cur->value << 1;
		while (cur->value >= PFBASE)
		{
			cur->value -= PFBASE;
			cur->left->inc += 1;
		}
		cur = cur->right;
	}
	cur = mng->d_e->left;
	while (cur)
	{
		cur->value += cur->inc;
		while (cur->value >= PFBASE)
		{
			cur->value -= PFBASE;
			cur->left->inc += 1;
		}
		cur->inc = 0;
		cur = cur->left; // attention debordement de bloc ? -> parfois creer nouveau bloc a droite ?
	}
	return (1);
}

ULL				find_most_significant_bit(ULL in)
{
	size_t			bits;

	bits = 1;
	while (bits < sizeof(in) * 8)
	{
		in |= in >> bits;
		bits = bits << 1;
	}
	return ((in >> 1) + 1);
}

unsigned char	add_shadow(PFMNG *mng, PFMNG *shadow)
{
	PF				*shadow_cur;
	PF				*cur;
	int				offset;

	cur = mng->d_e;
	shadow_cur = shadow->d_e;
	offset = cur->index - shadow_cur->index;
	while (offset-- > 0)
		if (!(cur = add_right(0, mng)))
			return (0);
	while (shadow_cur && cur)
	{
		cur->value += cur->inc;
		cur->inc = 0;
		cur->value += shadow_cur->value;
		while (cur->value >= PFBASE)
		{
			cur->value -= PFBASE;
			cur->left->inc += 1;
		} // debordement bloc
		cur = cur->left;
		shadow_cur = shadow_cur->left;
	}
	return (1);
}

unsigned char	decode_fraction(t_dbl *dbl, PFMNG *mng, PFMNG *shadow)
{
	unsigned int	left_offset;
	ULL				active_bit;

	shadow->d_s->value = PFBASE >> 1;
	left_offset = 0;
	while (++left_offset < dbl->fraction.left_offset)
		shift_right(shadow);
	active_bit = find_most_significant_bit(dbl->fraction.fraction);
	while (dbl->fraction.fraction > 0 && active_bit)
	{
		shift_right(shadow);
		if (dbl->fraction.fraction & active_bit)
		{
			add_shadow(mng, shadow);
			dbl->fraction.fraction -= active_bit;
		}
		active_bit = active_bit >> 1;
	}
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
	while ((dbl->exponent)-- > 0)
		shift_left(mng);
	while ((dbl->exponent)++ < 0)
		shift_right(mng);

	PF				*yo;
	yo = mng->i_e;
	while (yo)
	{
		printf("%llu\n", yo->value);
		yo = yo->right;
	}
	printf("\n");
	return (mng);
}
