/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:04:37 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/14 13:43:27 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//type x
//invalid flags : + 
//invalid modifier L
size_t			handle_x(va_list ap, t_str *head, t_mrk *mrk)
{
	mrk->base = 16;
	if (mrk->hashtag)
		mrk->len_prefix = 2;
	handle_u_t(ap, head, mrk);
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	if (mrk->len_prefix)
		add_prefix("x0", head);
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
