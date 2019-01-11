/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integer_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:02:45 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/11 14:56:26 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			uint_tostr(uintmax_t in, t_str *head, t_mrk *mrk, size_t index)
{
	size_t		i;

	if (in < mrk->base)
	{
		head->len = (mrk->mfw > index + 1) ? mrk->mfw : index + 1;
		head->txt = (char*)malloc(sizeof(char) * head->len);
		if (!head->txt)
			return ;
		i = -1;
		while (++i < head->len - (index + 1))
			head->txt[i] = 0;
	}
	else
		uint_tostr(in / mrk->base, head, mrk, index + 1);
	head->txt[head->len - index - 1] = symb_lc(in % mrk->base);
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
