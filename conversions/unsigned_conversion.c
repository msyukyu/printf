/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:19:17 by dabeloos          #+#    #+#             */
/*   Updated: 2019/02/23 19:22:34 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			re_uint_tostr(uintmax_t in, t_str *head, t_mrk *mrk,
			size_t index)
{
	size_t		i;

	if (in < mrk->base)
	{
		if (in == 0 && index == 0 && mrk->type != 'p')
			mrk->len_prefix = 0;
		i = (mrk->mfw > mrk->precision) ? mrk->mfw : mrk->precision;
		if (mrk->hashtag && (mrk->type == 'x' || mrk->type == 'X') &&
				!(index == 0 && in == 0))
			i += 2;
		head->len = (i > index + 1 + mrk->len_prefix) ? i : index + 1 +
			mrk->len_prefix;
		head->txt = (char*)malloc(sizeof(char) * head->len);
		if (!head->txt)
			return ;
		i = index;
		while (++i < mrk->precision)
			head->txt[head->len - 1 - i] = '0';
		while (i < head->len)
			head->txt[head->len - 1 - i++] = 0;
	}
	else
		re_uint_tostr(in / mrk->base, head, mrk, index + 1);
	head->txt[head->len - index - 1] = (mrk->type == 'X') ?
		symb_uc(in % mrk->base) : symb_lc(in % mrk->base);
}

void			uint_tostr(uintmax_t in, t_str *head, t_mrk *mrk, size_t index)
{
	size_t			i;

	if (!(in == 0 && index == 0 &&
				mrk->arg_precision && mrk->precision == 0))
		return re_uint_tostr(in, head, mrk, index);
	if (mrk->mfw == 0 && !(mrk->type == 'o' && mrk->hashtag))
		return ;
	i = (mrk->mfw > mrk->precision) ? mrk->mfw : mrk->precision;
	head->len = (i > mrk->len_prefix) ? i : mrk->len_prefix;
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!head->txt)
		return ;
	i = index - 1;
	while (++i < mrk->precision)
		head->txt[head->len - 1 - i] = '0';
	while (i < head->len)
		head->txt[head->len - 1 - i++] = 0;
}
