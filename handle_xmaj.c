/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_xmaj.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 17:05:28 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/11 19:33:19 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//type X
//invalid flags : + 
//invalid modifier : L
size_t			handle_x_maj(va_list ap, t_str *head, t_mrk *mrk)
{
	mrk->base = 16;
	if (mrk->hashtag)
		mrk->len_prefix = 2;
	handle_u_t(ap, head, mrk);
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	if (mrk->len_prefix)
		add_prefix("X0", head, mrk);
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