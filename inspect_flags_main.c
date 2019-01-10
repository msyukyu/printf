/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inspect_flags_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:22:05 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/10 17:01:18 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*inspect_flags(char *cur, t_mrk *mrk)
{
	size_t		pos;

	pos = -1;
	while (is_flag(cur[++pos]))
		;
	if (pos > 0)
	{
		mrk->flags = cur;
		sort_char(cur, 0, pos);
		mrk->len_flags = pos;
	}
	return (cur + pos);
}

char			*inspect_mfw(char *cur, t_mrk *mrk)
{
	size_t		pos;

	pos = -1;
	if (*cur == '*')
	{
		mrk->arg_mfw = 1;
		return (cur + 1);
	}
	while (is_number(cur[++pos]))
		;
	if (pos > 0)
		mrk->mfw = ft_atoui_limited(cur);
	return (cur + pos);
}

char			*inspect_precision(char *cur, t_mrk *mrk)
{
	size_t		pos;

	if (*cur == '.')
	{
		++cur;
		pos = -1;
		if (*cur == '*')
		{
			mrk->arg_precision = 1;
			return (cur + 1);
		}
		while (is_number(cur[++pos]))
			;
		if (pos > 0)
			mrk->precision = ft_atoui_limited(cur);
		return (cur + pos);
	}
	return (cur);
}

char			*inspect_length_modifier(char *cur, t_mrk *mrk)
{
	size_t		pos;

	pos = size_length_modifier(cur);
	if (pos > 0)
	{
		mrk->len_len_modif = pos;
		mrk->len_modif = cur;
	}
	return (cur + pos);
}

size_t			inspect_arg_type(va_list ap, char *cur, t_str *head,
		t_mrk *mrk)
{
	mrk->type = *cur;
	if (*cur == 'c')
		return (handle_c(ap, head, mrk));
	if (*cur == 's')
		return (handle_s(ap, head, mrk));
	if (*cur == 'p')
		return (handle_p(ap, head, mrk));
	if (*cur == 'd')
		return (handle_d(ap, head, mrk));
	if (*cur == 'i')
		return (handle_i(ap, head, mrk));
	if (*cur == 'o')
		return (handle_o(ap, head, mrk));
	if (*cur == 'u')
		return (handle_u(ap, head, mrk));
	if (*cur == 'x')
		return (handle_x(ap, head, mrk));
	if (*cur == 'X')
		return (handle_x_maj(ap, head, mrk));
	if (*cur == 'f')
		return (handle_f(ap, head, mrk));
	if (*cur == '%')
		return (handle_pctg(ap, head, mrk));
	return (0);
}
