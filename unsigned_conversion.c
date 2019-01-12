/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conversion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:19:17 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/12 15:19:28 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			uint_tostr(uintmax_t in, t_str *head, t_mrk *mrk, size_t index)
{
	size_t		i;

	if (in < mrk->base)
	{
		if (in == 0 && index == 0 && mrk->type != 'p')
			mrk->len_prefix = 0;
		i = (mrk->mfw > mrk->precision) ? mrk->mfw : mrk->precision;
		head->len = (i > index + 1 + mrk->len_prefix) ? i : index + 1 +
			mrk->len_prefix;
		head->txt = (char*)malloc(sizeof(char) * head->len);
		if (!head->txt)
			return ;
		i = index;
		while (++i < mrk->precision)
			head->txt[head->len - 1 - i] = '0';
		while (++i < head->len)
			head->txt[head->len - 1 - i] = 0;
	}
	else
		uint_tostr(in / mrk->base, head, mrk, index + 1);
	head->txt[head->len - index - 1] = (mrk->type == 'X') ?
		symb_uc(in % mrk->base) : symb_lc(in % mrk->base);
	return ;
}
