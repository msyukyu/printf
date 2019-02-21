/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 16:16:27 by dabeloos          #+#    #+#             */
/*   Updated: 2019/02/21 22:58:31 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

	//type f
	//invalid modifier : ll h hh
size_t		handle_f(va_list ap, t_str *head, t_mrk *mrk)
{
	PFMNG		*mng;

	mrk->base = 10;
	if (mrk->len_modif && *(mrk->len_modif) == 'L')
	{
		//ldouble_bits_tostr(va_arg(ap, long double), head);
		mng = pf_boot(va_arg(ap, long double));
		if (mng == NULL)
			return (0);
		float_tostr(mng, head, mrk);
		//clean_pfmng(mng);
	}
	else
	{
		mng = pf_boot((long double)va_arg(ap, double));
		if (mng == NULL)
			return (0);
		float_tostr(mng, head, mrk);
		//clean_pfmng(mng);
		//double_bits_tostr(va_arg(ap, double), head);
	}
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	if (mrk->minus)
		left_justify(' ', head, mrk);
	else
		right_justify(' ', head, mrk);
	return ((head->txt) ? head->len : 0);
}
