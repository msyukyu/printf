/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_conversion_support.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 14:07:12 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/13 14:55:09 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static unsigned char	*uc_memcpy(unsigned char *dst, const void *src,
		size_t n)
{
	size_t			i;

	i = -1;
	while (++i < n)
		dst[i] = *((unsigned char*)src + i);
	return (dst);
}

unsigned char			*uc_memmove(unsigned char *dst, const void *src,
		size_t n)
{
	if ((void*)dst < src)
		return (uc_memcpy(dst, src, n));
	while (n > 0)
	{
		--n;
		dst[n] = *((unsigned char *)src + n);
	}
	return (dst);
}
