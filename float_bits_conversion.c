/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_bits_conversion.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 17:53:15 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/14 18:29:53 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

unsigned char			*store_ldouble_bits(long double in)
{
	unsigned char	*bits;

	bits = (unsigned char*)malloc(sizeof(in));
	if (!bits)
		return (NULL);
	bits = uc_memmove(bits, &in, sizeof(in));
	return (bits);
}

unsigned char			*store_double_bits(double in)
{
	unsigned char	*bits;

	bits = (unsigned char*)malloc(sizeof(in));
	if (!bits)
		return (NULL);
	bits = uc_memmove(bits, &in, sizeof(in));
	return (bits);
}

void					ldouble_bits_tostr(long double in, t_str *head)
{
	unsigned char	*bits;
	size_t			index;
	size_t			dots;

	bits = store_ldouble_bits(in);
	if (!bits)
		return ;
	head->len = sizeof(char) * 80 + 3 * sizeof(char);
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!bits)
		return ;
	index = -1;
	dots = 0;
	while (++index < head->len - 3)
	{
		head->txt[index + dots] = '0' +
			(char)((bits[(head->len - 2) / 8 - 1 - index / 8] &
			(((unsigned char)1) << (7 - index % 8))) >> (7 - index % 8));
		if (index == 0 || index == 15 || index == 16)
			head->txt[index + ++dots] = '.';
	}
	free(bits);


	//t_dbl *dbl = extract_ldouble_infos(in);
	//printf("%d\n", dbl->exponent);
	//printf("%d\n", dbl->sign);
	//printf("%d\n", dbl->normalized);
	//printf("%ju\n", dbl->fraction);
}

void					double_bits_tostr(double in, t_str *head)
{
	unsigned char	*bits;
	size_t			index;
	size_t			dots;

	bits = store_double_bits(in);
	if (!bits)
		return ;
	head->len = sizeof(in) * 8 + 2 * sizeof(char);
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!bits)
		return ;
	index = -1;
	dots = 0;
	while (++index < head->len - 2)
	{
		head->txt[index + dots] = '0' +
			(char)((bits[(head->len - 2) / 8 - 1 - index / 8] &
			(((unsigned char)1) << (7 - index % 8))) >> (7 - index % 8));
		if (index == 0 || index == 11)
			head->txt[index + ++dots] = '.';
	}
	free(bits);


	//t_dbl *dbl = extract_double_infos(in);
	//printf("%d\n", dbl->exponent);
	//printf("%d\n", dbl->sign);
	//printf("%d\n", dbl->normalized);
	//printf("%ju\n", dbl->fraction);
}
