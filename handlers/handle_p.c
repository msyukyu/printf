/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:02:04 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/14 13:43:17 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//type p
//invalid flags : 0+ #
//invalid precision
//invalid modifier : all
//uintmax_t
//min : mfw
//else number size
//- : left justified
size_t			handle_p(va_list ap, t_str *head, t_mrk *mrk)
{
	mrk->base = 16;
	mrk->hashtag = 1;
	mrk->len_prefix = 2;
	uint_tostr((unsigned long)va_arg(ap, void*), head, mrk, 0);
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	add_prefix("x0", head);
	if (mrk->minus)
		left_justify(' ', head, mrk);
	else
		right_justify(' ', head, mrk);
	return ((head->txt) ? head->len : 0);
}
