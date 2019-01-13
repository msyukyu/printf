/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 21:02:51 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/13 17:01:46 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned char	*store_ldouble_bits(long double in)
{
	unsigned char	*display_bits;

	display_bits = (unsigned char*)malloc(sizeof(in));
	if (!display_bits)
		return (NULL);
	display_bits = uc_memmove(display_bits, &in, sizeof(in));
	return (display_bits);
}

static unsigned char	*store_double_bits(double in)
{
	unsigned char	*display_bits;

	display_bits = (unsigned char*)malloc(sizeof(in));
	if (!display_bits)
		return (NULL);
	display_bits = uc_memmove(display_bits, &in, sizeof(in));
	return (display_bits);
}

void					ldouble_bits_tostr(long double in, t_str *head,
		t_mrk *mrk)
{
	unsigned char	*display_bits;
	size_t			index;
	size_t			dots;

	display_bits = store_ldouble_bits(in);
	if (!display_bits)
		return ;
	head->len = sizeof(char) * 80 + 2 * sizeof(char);
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!display_bits)
		return ;
	index = -1;
	dots = 0;
	while (++index < head->len - 2)
	{
		head->txt[index + dots] = '0' +
			(char)((display_bits[(head->len - 2) / 8 - 1 - index / 8] &
			(((unsigned char)1) << (7 - index % 8))) >> (7 - index % 8));
		if (index == 0 || index == 15 || index == 16)
			head->txt[index + ++dots] = '.';
	}
}

void					double_bits_tostr(double in, t_str *head, t_mrk *mrk)
{
	unsigned char	*display_bits;
	size_t			index;
	size_t			dots;

	display_bits = store_double_bits(in);
	if (!display_bits)
		return ;
	head->len = sizeof(in) * 8 + 2 * sizeof(char);
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!display_bits)
		return ;
	index = -1;
	dots = 0;
	while (++index < head->len - 2)
	{
		head->txt[index + dots] = '0' +
			(char)((display_bits[(head->len - 2) / 8 - 1 - index / 8] &
			(((unsigned char)1) << (7 - index % 8))) >> (7 - index % 8));
		if (index == 0 || index == 11)
			head->txt[index + ++dots] = '.';
	}
}
