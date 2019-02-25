/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_ornament.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:02:41 by dabeloos          #+#    #+#             */
/*   Updated: 2019/02/25 00:41:21 by dabeloos         ###   ########.fr       */
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
		pos = offset - 1;
		while (++pos < head->len)
			head->txt[pos - offset] = head->txt[pos];
	}
	pos = head->len - offset - 1;
	while (++pos < head->len)
		head->txt[pos] = filler;
}

void			right_justify(char filler, t_str *head, t_mrk *mrk)
{
	size_t		offset;

	offset = -1;
	while (++offset < mrk->mfw && !head->txt[offset])
		head->txt[offset] = filler;
}

void			char_right_justify(char filler, t_str *head)
{
	size_t		offset;

	offset = -1;
	while (++offset < head->len - 1)
		head->txt[offset] = filler;
}

void			char_left_justify(char filler, t_str *head)
{
	size_t		offset;
	size_t		pos;

	offset = -1;
	while (++offset < head->len - 1)
		;
	if (offset > 0)
	{
		pos = offset - 1;
		while (++pos < head->len)
			head->txt[pos - offset] = head->txt[pos];
	}
	pos = head->len - offset - 1;
	while (++pos < head->len)
		head->txt[pos] = filler;
}

void			add_prefix(char *prefix, t_str *head)
{
	size_t		offset;
	size_t		pos;

	offset = -1;
	while (++offset < head->len && !head->txt[offset])
		;
	pos = -1;
	--offset;
	while (prefix[++pos] && offset >= pos)
		head->txt[offset - pos] = prefix[pos];
}

void			force_prefix(char *prefix, t_str *head)
{
	size_t		pos;

	pos = -1;
	while (prefix[++pos])
		head->txt[pos] = prefix[pos];
}

void			appleft_prefix(char *prefix, t_str *head, size_t len_prefix,
		char ignore)
{
	size_t		offset;
	size_t		pos;

	offset = -1;
	while (head->txt[++offset] != ignore)
		;
	pos = offset - 1;
	while (++pos < offset + len_prefix)
		head->txt[pos] = head->txt[pos - len_prefix];
	force_prefix(prefix, head);
}

char			next_digit(t_str *head)
{
	size_t		pos;

	pos = -1;
	while (++pos < head->len)
	{
		if (head->txt[pos] != '\0')
			return (head->txt[pos]);
	}
	return ('\0');
}
