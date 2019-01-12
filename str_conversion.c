/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_conversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:20:04 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/12 15:20:13 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			print_null(t_str *head, t_mrk *mrk)
{
	ustr_tostr("(null)", head, mrk);
}

void			ustr_tostr(char *in, t_str *head, t_mrk *mrk)
{
	size_t		len;
	size_t		i;

	if (in == NULL)
		return (print_null(head, mrk));
	len = -1;
	while (in[++len])
		;
	if (mrk->arg_precision)
		len = (len < mrk->precision) ? len : mrk->precision;
	head->len = (len > mrk->mfw) ? len : mrk->mfw;
	head->txt = (char*)malloc(sizeof(char) * head->len);
	if (!head->txt && head->len != 0)
		return ;
	i = -1;
	while (++i < len)
		head->txt[head->len - len + i] = in[i];
	i = -1;
	while (++i < head->len - len)
		head->txt[i] = 0;
}
