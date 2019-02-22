/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_boot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 12:36:10 by dabeloos          #+#    #+#             */
/*   Updated: 2019/02/22 17:35:44 by dabeloos         ###   ########.fr       */
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

void			add_dot(t_str *head, PFPMNG mng)
{
	head->txt[head->len - mng.index - 1] = '.';
}

void			rank_tostr(t_str *head, t_mrk *mrk, PFPMNG mng,
		unsigned char rank_size)
{
	size_t		index;

	index = -1;
	while (++index < rank_size - mng.cur->size)
		mng.cur->value /= (ULL)mrk->base;
	index = -1;
	while (++index < mng.cur->size)
	{
		if (mng.cur->value == 0)
			head->txt[head->len - (mng.index + index) - 1] = '0';
		else
		{
			head->txt[head->len - (mng.index + index) - 1] =
				symb_lc(mng.cur->value % (ULL)mrk->base);
			mng.cur->value /= (ULL)mrk->base;
		}
	}
}

void			ornate_pfloat(t_str *head, t_mrk *mrk, PFPMNG mng, char sign)
{
	size_t		i;
	size_t		precision;

	i = mng.index;
	precision = head->len - ((sign == -1 || mrk->plus || mrk->blank) ? 1 : 0);
	while (++i < precision && mrk->zero)
		head->txt[head->len - i - 1] = '0';
	if (sign == -1)
		head->txt[head->len - 1 - i++] = '-';
	else if (mrk->plus)
		head->txt[head->len - 1 - i++] = '+';
	else if (mrk->blank)
		head->txt[head->len - 1 - i++] = ' ';
	while (i < head->len)
		head->txt[head->len - 1 - i++] = 0;
}

void			malloc_float_str(PFMNG *in, t_str *head, t_mrk *mrk,
		PFPMNG mng)
{
	ULL				value;
	size_t			index;
	unsigned char	prefix;

	value = mng.cur->value;
	index = mng.index;
	if (mng.cur->value < (ULL)mrk->base)
	{
		prefix = (in->sign == -1 || mrk->plus || mrk->blank) ? 1 : 0;
		head->len = (mrk->mfw > prefix + mng.index + 1) ?
			mrk->mfw : prefix + mng.index + 1;
		head->txt = (char*)malloc(sizeof(char) * head->len);
		if (!head->txt)
			return ;
		ornate_pfloat(head, mrk, mng, in->sign);
	}
	else
	{
		mng.cur->value /= (ULL)mrk->base;
		mng.index++;
		malloc_float_str(in, head, mrk, mng);
	}
	head->txt[head->len - index - 1] =
		symb_lc(value % (ULL)mrk->base);
}

void			main_recursion(PFMNG *in, t_str *head, t_mrk *mrk, PFPMNG mng)
{
	size_t		index;

	if ((mng.cur == in->i_e || (mng.cur->left == in->i_e &&
		in->i_e->value == 0 && in->i_e != in->i_s)) && mng.dot_index != 0)
	{
		malloc_float_str(in, head, mrk, mng);
		return ; // pas oublier de compter les index ici
	}
	else
	{
		index = mng.index;
		mng.index += (mng.cur == in->i_s && !mng.dot_index) ? 1 : mng.cur->size;
		if (mng.cur == in->i_s)
			mng.dot_index = (!mng.dot_index) ? 1 : 2;
		if (mng.dot_index != 1)
			mng.cur = mng.cur->left;
		main_recursion(in, head, mrk, mng);
		mng.index = index;
		if (mng.dot_index != 1)
			mng.cur = mng.cur->right;
	}
	if (mng.dot_index == 1)
		add_dot(head, mng);
	else
		rank_tostr(head, mrk, mng, in->i_s->size);
}

void			ignore_zeros(PFPMNG *mng)
{
	ULL		tmp;

	tmp = mng->cur->value;
	while (!(tmp % 10))
	{
		mng->cur->size--;
		tmp /= 10;
	}
}

unsigned char	d_rank_right(PF **cur, unsigned char d_rank,
		unsigned char rank_size)
{
	if (d_rank == 1)
	{
		*cur = (*cur)->right;
		return (rank_size);
	}
	return (d_rank - 1);
}

ULL				generate_base(unsigned char d_rank)
{
	ULL			base;

	base = 1;
	while (--d_rank > 0)
		base *= 10;
	return (base);
}

unsigned char	extract_digit(ULL value, unsigned char d_rank)
{
	return ((value / generate_base(d_rank)) % 10);
}

unsigned char	find_nonzero_digit(PF *cur, unsigned char d_rank,
		unsigned char rank_size)
{
	unsigned char	s_rank;
	unsigned char	prev_prev;

	s_rank = d_rank_right(&cur, d_rank, rank_size);
	prev_prev = extract_digit(cur->value, s_rank);
	if (cur == NULL)
		return (0);
	else if (prev_prev == 0)
		return (find_nonzero_digit(cur, s_rank, rank_size));
	else
		return (prev_prev);
}

void			round_up(PFMNG *in, PFPMNG *mng, unsigned char d_rank)
{
	mng->cur->inc = generate_base(d_rank);
	add_inc(mng->cur, in);
}

void			round_pfloat(PFMNG *in, PFPMNG *mng, int keep)
{
	unsigned char	last_digit;
	unsigned char	prev_digit;
	unsigned char	d_rank;
	PF				*cur;

	while (keep <= 0)
	{
		keep += (int)mng->cur->size;
		mng->cur = mng->cur->left;
	}
	mng->cur = mng->cur->right;
	mng->cur->size = keep;
	d_rank = in->i_s->size - keep + 1;
	cur = mng->cur;
	last_digit = extract_digit(cur->value, d_rank);
	d_rank = d_rank_right(&cur, d_rank, in->i_s->size);
	prev_digit = extract_digit(cur->value, d_rank);
	if (prev_digit > 5 || (prev_digit == 5 && (last_digit % 2 != 0 ||
		find_nonzero_digit(cur, d_rank, in->i_s->size) != 0)))
		round_up(in, mng, in->i_s->size - keep + 1);
}

void			zeros_or_round(PFMNG *in, t_mrk *mrk, PFPMNG *mng)
{
	int				keep;
	int				rejected;
	PF				*cur;

	ignore_zeros(mng);
	rejected = mng->cur->size;
	cur = mng->cur->left;
	while (cur != in->i_s)
	{
		rejected += in->i_s->size;
		cur = cur->left;
	}
	mrk->precision = (!mrk->arg_precision) ? 6 : mrk->precision;
	keep = (int)(mrk->precision) - rejected;
	rejected = in->i_s->size - mng->cur->size;
	if (keep >= rejected)
	{
		mng->more_zeros = keep - rejected;
		mng->index = mng->more_zeros;
		mng->cur->size += rejected;
	}
	else if (keep >= 0)
		mng->cur->size += keep;
	else
		round_pfloat(in, mng, keep);
}

void			float_tostr(PFMNG *in, t_str *head, t_mrk *mrk)
{
	PFPMNG			mng;

	mng.index = 0;
	mng.dot_index = 0;
	mng.cur = in->d_e;
	mng.more_zeros = 0;
	while (mng.cur->value == 0 && mng.cur != in->i_s)
		mng.cur = mng.cur->left;
	if (mng.cur == in->i_s)
	{
		if (mrk->hashtag)
			mng.cur = mng.cur->right;
		else
			mng.dot_index = 2;
	}
	if (!mng.dot_index)
		zeros_or_round(in, mrk, &mng);
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
	free(dbl);
	clean_pfmng(shadow);
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
