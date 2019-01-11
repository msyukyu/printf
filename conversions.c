/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 20:49:59 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/11 21:24:05 by dabeloos         ###   ########.fr       */
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
		head->len = (mrk->mfw > index + 1 + mrk->len_prefix) ? mrk->mfw :
			index + 1 + mrk->len_prefix;
		head->txt = (char*)malloc(sizeof(char) * head->len);
		if (!head->txt)
			return ;
		i = -1;
		while (++i < head->len - (index + 1))
			head->txt[i] = 0;
	}
	else
		uint_tostr(in / mrk->base, head, mrk, index + 1);
	head->txt[head->len - index - 1] = (mrk->type == 'X') ?
		symb_uc(in % mrk->base) : symb_lc(in % mrk->base);
	return ;
}

void			uchar_tostr(unsigned char in, t_str *head, t_mrk *mrk)
{
	size_t		i;

	head->len = (mrk->mfw > 1) ? mrk->mfw : 1;
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!head->txt)
		return ;
	head->txt[head->len - 1] = (char)in;
	i = -1;
	while (++i < head->len - 1)
		head->txt[i] = 0;
}

void			ustr_tostr(char *in, t_str *head, t_mrk *mrk)
{
	size_t		len;
	size_t		i;

	len = -1;
	while (in[++len])
		;
	if (mrk->arg_precision)
		len = (len < mrk->precision) ? len : mrk->precision;
	head->len = (len > mrk->mfw) ? len : mrk->mfw;
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!head->txt)
		return ;
	i = -1;
	while (++i < len)
		head->txt[head->len - len + i] = in[i];
	i = -1;
	while (++i < head->len - len)
		head->txt[i] = 0;
}
