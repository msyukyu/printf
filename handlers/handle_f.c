/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:16:27 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/13 19:37:31 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

	//type f
	//invalid modifier : ll h hh
size_t		handle_f(va_list ap, t_str *head, t_mrk *mrk)
{
	if (mrk->len_modif && *(mrk->len_modif) == 'L')
		ldouble_bits_tostr(va_arg(ap, long double), head);
	else
		double_bits_tostr(va_arg(ap, double), head);
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	return ((head->txt) ? head->len : 0);
}
