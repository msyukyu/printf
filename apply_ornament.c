/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ornament.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:02:41 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/09 21:36:51 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			left_justify(char filler, t_str *head, t_mrk *mrk)
{
	size_t		offset;
	size_t		pos;

	offset = -1;
	while (++offset < mrk->mfw && !head->txt[offset])
		;
	if (offset > 0)
	{
		pos = -1;
		while (++pos < head->len)
			head->txt[pos] = head->txt[pos + offset];
	}
	pos = head->len - 1;
	while (++pos < mrk->mfw)
		head->txt[pos] = filler;
}

void			right_justify(char filler, t_str *head, t_mrk *mrk)
{
	size_t		offset;
	size_t		pos;

	offset = mrk->mfw;
	while (--offset > -1 && !head->txt[offset])
		;
	if (offset < mrk->mfw - 1)
	{
		pos = -1;
		while (++pos < head->len)
			head->txt[mrk->mfw - pos] = head->txt[head->len - pos];
	}
	pos = mrk->mfw - head->len;
	while (--pos > -1)
		head->txt[pos] = filler;
}
