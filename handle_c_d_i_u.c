/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_c_d_i_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:31:46 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/10 15:58:45 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

	//type c
	//invalid flags : 0+ #
	//invalid precision
	//invalid modifier : all
size_t	handle_c(va_list ap, t_str *head, t_mrk *mrk)
{
	//size_t
	//min : mfw
	//else : number size
	//- : left justified
	mrk->base = 10;
	uint_tostr(va_arg(ap, unsigned int), head, mrk, 0);
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	if (search_flag('-', mrk))
		left_justify(' ', head, mrk);
	return ((head->txt) ? head->len : 0);
}

	//type d
	//invalid flags : #
	//invalid modifier : L
size_t			handle_d(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}

	//type i
	//invalid flags : #
	//invalid modifier : L
size_t			handle_i(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}

	//type u
	//invalid flags : + #
	//invalid modifier : L
size_t			handle_u(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
