/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_extraction_support.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 18:41:46 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/13 21:00:31 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char					extract_float_sign(unsigned char *bits, size_t size)
{
	return (((bits[size - 1] & (((unsigned char)1) << 7)) >> 7) ? -1 : 1);
}

int						extract_float_exponent(size_t len, size_t offset,
							unsigned char *bits, size_t size)
{
	size_t			i;
	unsigned int	out;

	i = offset - 1;
	out = 0;
	while (++i < offset + len)
	{
		out |= ((unsigned int)(bits[size - 1 - i / 8] &
					(((unsigned char)1) << (7 - i % 8))) >> (7 - i % 8)) <<
						(len + offset - 1 - i);
	}
	return ((int)out - ((int)(((unsigned int)1) << (len - 1))) + 1);
}

char					extract_ldouble_normalized(size_t offset,
							unsigned char *bits, size_t size)
{
	return ((char)((bits[size - 1 - offset / 8] & (((unsigned char)1) <<
						(7 - offset % 8))) >> (7 - offset % 8)));
}

uintmax_t				extract_float_fraction(size_t len, size_t offset,
							unsigned char *bits, size_t size)
{
	size_t			i;
	uintmax_t		out;

	i = offset - 1;
	out = 0;
	while (++i < offset + len)
	{
		out |= ((uintmax_t)(bits[size - 1 - i / 8] &
					(((unsigned char)1) << (7 - i % 8))) >> (7 - i % 8)) <<
						(len + offset - 1 - i);
	}
	return (out);
}
