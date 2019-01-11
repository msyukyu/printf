/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/11 21:24:17 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
		cur = ft_strncpy(cur, (const char*)head->txt, head->len);
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
	write(1, out, len);
	va_end(ap);
	free(out);
	return (len);
}

int				main(void)
{
	//ft_printf("_%c_%-c_%10c_%-10c_", 1568, 68843, 48654, 46812);
	//printf("\n%10c_%-10c", 192, 82);
	//ft_printf("%10u_%-10u_%-010u", 123, 456, 789);
	//printf("\n%10u_%-10u_%-010u", 123, 456, 789);
	//ft_printf("%10p_%10p_%10p", NULL, "COUCOU", "COUCOU");
	//printf("\n");
	//printf("%10p_%10p_%10p", NULL, "COUCOU", "COUCOU");
	ft_printf("%.s", "coucou");
	printf("\n");
	printf("%.s", "coucou");
	return (0);
}
