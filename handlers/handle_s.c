/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:07:30 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/14 20:27:44 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//type s
//invalids flags : 0+ #
//invalid modifier : all
//char *
//max : precision
//min : mfw
//else : string size_t
//- : left justified
size_t			handle_s(va_list ap, t_str *head, t_mrk *mrk)
{
	ustr_tostr((char*)va_arg(ap, char*), head, mrk);
	if (!head->txt && head->len != 0)
		return (0);
	if (head->len != 0)
		head->is_raw = 0;
	if (mrk->minus)
		left_justify(' ', head, mrk);
	else
		right_justify(' ', head, mrk);
	if (head->len == 0)
		return (-1);
	return ((head->txt) ? head->len : 0);
}