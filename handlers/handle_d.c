/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:58:26 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/12 16:57:06 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			handle_s_t(va_list ap, t_str *head, t_mrk *mrk)
{
	if (mrk->len_modif)
	{
		if (*(mrk->len_modif) == 'l')
		{
			if (mrk->len_len_modif == 2)
				int_tostr((long long)va_arg(ap, intmax_t), head, mrk, 0);
			else
				int_tostr((long)va_arg(ap, intmax_t), head, mrk, 0);
		}
		else if (*(mrk->len_modif) == 'h')
		{
			if (mrk->len_len_modif == 2)
				int_tostr((char)va_arg(ap, intmax_t), head, mrk, 0);
			else
				int_tostr((short)va_arg(ap, intmax_t), head, mrk, 0);
		}
	}
	else
		int_tostr((int)va_arg(ap, intmax_t), head, mrk, 0);
}

//type d
//invalid flags : #
//invalid modifier : L
size_t			handle_d(va_list ap, t_str *head, t_mrk *mrk)
{
	mrk->base = 10;
	handle_s_t(ap, head, mrk);
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	if (mrk->minus)
		left_justify(' ', head, mrk);
	else
	{
		if (mrk->zero)
			right_justify('0', head, mrk);
		else
			right_justify(' ', head, mrk);
	}
	return ((head->txt) ? head->len : 0);
}
