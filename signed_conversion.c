/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_conversion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:52:22 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/13 14:52:20 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void			ornate_signed(t_str *head, t_mrk *mrk, size_t i, char sign)
{
	while (++i < mrk->precision)
		head->txt[head->len - 1 - i] = '0';
	if (sign == -1)
		head->txt[head->len - 1 - i++] = '-';
	else if (mrk->plus)
		head->txt[head->len - 1 - i++] = '+';
	else if (mrk->blank)
		head->txt[head->len - 1 - i++] = ' ';
	while (i++ < head->len)
		head->txt[head->len - 1 - i] = 0;
}

void			int_tostr(intmax_t in, t_str *head, t_mrk *mrk, size_t index)
{
	char			sign;
	size_t			i;
	unsigned char	prefix;

	sign = 1;
	if (in < 0)
		sign = -1;
	if (in > -1 * (intmax_t)mrk->base && in < (intmax_t)mrk->base)
	{
		i = (mrk->mfw > mrk->precision) ? mrk->mfw : mrk->precision;
		prefix = (sign == -1 || mrk->plus || mrk->blank) ? 1 : 0;
		head->len = (i > index + 1 + prefix) ? i : index + 1 + prefix;
		head->txt = (char*)malloc(sizeof(char) * head->len);
		if (!head->txt)
			return ;
		ornate_signed(head, mrk, index, sign);
	}
	else
		int_tostr(in / (intmax_t)mrk->base, head, mrk, index + 1);
	head->txt[head->len - index - 1] = symb_lc(sign *
			(in % (intmax_t)mrk->base));
}
