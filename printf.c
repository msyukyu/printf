/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/09 20:49:15 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*str_lst_join(t_str *slst, size_t len)
{
	char		*out;
	char		*cur;
	t_str		*head;

	if (!slst || !(out = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	cur = out;
	head = slst;
	while (head)
	{
		cur = ft_strncpy(cur, (const char*)head->txt, head->len);
		cur += head->len;
		head = head->next;
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
	va_end(ap);
	return (len);
}

int				main(void)
{
	return (0);
}
