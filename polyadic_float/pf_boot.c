/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_boot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:36:10 by dabeloos          #+#    #+#             */
/*   Updated: 2019/02/18 16:59:26 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

PF				*add_right(ULL value, PFMNG *mng)
{
	if (!init_pf(value, mng->d_e, NULL))
		return (NULL);
	mng->d_e = mng->d_e->right;
	return (mng->d_e);
}

PF				*add_left(ULL value, PFMNG *mng)
{
	if (!init_pf(value, NULL, mng->i_e))
		return (NULL);
	mng->i_e = mng->i_e->left;
	return (mng->i_e);
}

unsigned char	add_inc(PF *pf, PFMNG *mng)
{
	pf->value += pf->inc;
	while (pf->value >= PFBASE)
	{
		pf->value -= PFBASE;
		if (!pf->left && !add_left(0, mng))
			return (0);
		pf->left->inc += 1;
	}
	pf->inc = 0;
	return (1);
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
		if (!add_inc(cur, mng))
			return (0);
		cur = cur->left;
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
		if (!add_inc(cur, mng))
			return (0);
		cur = cur->left;
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
		cur->value += shadow_cur->value;
		if (!add_inc(cur, mng))
			return (0);
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
	while (left_offset++ < dbl->fraction.left_offset)
		shift_right(shadow);
	active_bit = find_most_significant_bit(dbl->fraction.fraction);
	while (dbl->fraction.fraction > 0 && active_bit)
	{
		if (dbl->fraction.fraction & active_bit)
		{
			add_shadow(mng, shadow);
			dbl->fraction.fraction -= active_bit;
		}
		active_bit = active_bit >> 1;
		shift_right(shadow);
	}
	return (1);
}

void			shift_rank_left(PFPMNG *mng)
{
	mng->cur = mng->cur->left;
	mng->value = mng->cur->value;
}

void			shift_rank_right(PFPMNG *mng)
{
	mng->cur = mng->cur->right;
	mng->value = mng->cur->value;
}

void			add_dot(t_str *head, PFPMNG mng)
{
	head->txt[head->len - mng.index - 1] = '.';
}

void			decimal_tostr(PFMNG *in, t_str *head, t_mrk *mrk, PFPMNG mng)
{
	
}

void			integer_tostr(PFMNG *in, t_str *head, t_mrk *mrk, PFPMNG mng)
{

}

void			malloc_float_str(PFMNG *in, t_str *head, t_mrk *mrk,
		PFPMNG mng)
{
	
}

void			main_recursion(PFMNG *in, t_str *head, t_mrk *mrk, PFPMNG mng)
{
	if (mng.cur == in->i_e)
	{
		malloc_float_str(in, head, mrk, mng);
		return ; // pas oublier de compter les index ici
	}
	else
	{
		mng.index += mng.inc_index;
		if (mng.cur == in->i_s)
		{
			if (!mng.dot_index && (mng.inc_index = 1))
				mng.dot_index = 1;
			else if ((mng.inc_index = 18))
				mng.dot_index = 2;
		}
		else if (mng.inc_index != 18)
			mng.inc_index = 18;
		shift_rank_left(&mng);
		main_recursion(in, head, mrk, mng);
	}
	if (!mng.dot_index)
		decimal_tostr(in, head, mrk, mng);
	else if (mng.dot_index == 1)
		add_dot(head, mng);
	else
		integer_tostr(in, head, mrk, mng);
}

void			find_out_zeros(PFMNG *in, t_mrk *mrk, PFPMNG *mng)
{
	int			rejected;
	int			decimals;
	int			zeros;
	PF			*cur;

	rejected = 0;
	while (!(mng->value % 10))
	{
		++rejected;
		mng->value = mng->value / 10;
	}
	decimals = 18 - rejected;
	cur = mng->cur->left;
	while (cur != in->i_s)
		decimals += 18;
	mrk->precision = (!mrk->arg_precision) ? 6 : mrk->precision;
	zeros = decimals - (int)(mrk->precision);
	if (zeros >= rejected)
	{
		mng->more_zeros = zeros - rejected;
		mng->index = mng->more_zeros;
		mng->inc_index = 18;
	}
	else if (zeros >= 0)
		mng->inc_index = 18 - rejected + zeros;
	else
	{
		decimals += zeros;
		if (decimals >= 0)
			//recuperer le digit precedent dans ce bloc ci, si == 0, passer au
			//bloc suivant
		while (decimals < 0)
		{
			
		}
		//cas ou on n'affiche pas toutes les decimales
	}
}

void			float_tostr(PFMNG *in, t_str *head, t_mrk *mrk)
{
	PFPMNG			mng;

	mng.prev_decimal = 10;
	mng.index = 0;
	mng.dot_index = 0;
	mng.cur = in->d_e;
	mng.value = mng.cur->value;
	mng.more_zeros = 0;
	while (mng.cur->value == 0 && mng.cur != in->i_s)
		shift_rank_left(&mng);
	if (mng.cur == in->i_s)
		mng.dot_index = (mrk->hashtag) ? 1 : 2;
	if (!mng.dot_index)
		find_out_zeros(in, mrk, &mng);
		//gerer la precision (ajouter masse zero, ou oublier certains digits)
		//calculer le nombre de digits a ajouter (peut etre inferieur a 18)
		//pour le premier bloc (mng.inc_index) -> mng.more_zeros
	main_recursion(in, head, mrk, mng);
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
	if (dbl->exponent > 0)
		while ((dbl->exponent)-- > 0)
			shift_left(mng);
	else
		while ((dbl->exponent)++ < 0)
			shift_right(mng);
	/*
	PF				*yo;
	yo = mng->i_e;
	while (yo)
	{
		printf("%llu\n", yo->value);
		yo = yo->right;
	}
	printf("\n");
	*/
	return (mng);
}
