/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2019/02/25 12:31:36 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*str_lst_join(t_str *slst, size_t len)
{
	char		*out;
	char		*cur;
	t_str		*head;
	t_str		*prev;

	if (!slst || !(out = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	cur = out;
	head = slst;
	while (head)
	{
		ft_strncpy(cur, (const char*)head->txt, head->len);
		cur += head->len;
		prev = head;
		head = head->next;
		if (!prev->is_raw)
			free(prev->txt);
		free(prev);
	}
	return (out);
}

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	t_str		*slst;
	char		*out;
	size_t		len;

	len = 0;
	va_start(ap, format);
	slst = decode_format(ap, format, &len);
	out = str_lst_join(slst, len);
	if (out)
		write(1, out, len);
	va_end(ap);
	free(out);
	return ((!out) ? -1 : (int)len);
}
