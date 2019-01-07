/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/07 17:04:17 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_str			*init_str(t_str *s)
{
	s = (t_str*)malloc(sizeof(t_str));
	if (!s)
		return (NULL);
	s->txt = NULL;
	s->len = 0;
	s->next = NULL;
	s->is_raw = 1;
	return (s);
}

t_str			*clean_str(t_str *s)
{
	if (s)
	{
		if (!s->is_raw)
			free(s->txt);
		clean_str(s->next);
		free(s);
	}
	return (NULL);
}

void			init_mrk(t_mrk *m)
{
	m->flags = NULL;
	m->len_flags = 0;
	m->mfw = 0;
	m->period = 0;
	m->precision = 0;
	m->type = 0;
}

unsigned char	is_flag(char in)
{
	return (in == '-' || in == '0' || in == '+' || in == ' ' || in == '#');
}

char			*format_arg(va_list ap, char *cur, t_str *head)
{
	size_t		pos;
	t_mrk		mrk;

	++cur;
	pos = -1;
	init_mrk(&mrk);
	while (is_flag(cur[++pos]))
		;
	mrk.flags = cur;
	mrk.len_flags = pos;
	cur = cur + pos;
	mrk.mfw = ft_atoi(cur);
	while (is_number(*cur))
		++cur;
	if (*cur == '.')
	{
		++cur;
		mrk.period = 1;
		mrk.precision = ft_atoi(cur);
	}
	return (cur + pos);
}

char			*copy_arg(char *cur, t_str *head)
{
	size_t		pos;

	pos = -1;
	while (cur[++pos] && cur[pos] != '%')
		;
	head->txt = cur;
	head->len = pos;
	return (cur + pos);
}

t_str			*decode_format(va_list ap, const char *format)
{
	char		*cur;
	t_str		*root;
	t_str		*head;
	t_str		*prev;

	if (!init_str(root))
		return (NULL);
	head = root;
	prev = NULL;
	cur = (char*)format;
	while (1)
	{
		if (*cur == '%')
			cur = format_arg(ap, cur, head);
		else
			cur = copy_arg(cur, head);
		if (!(*cur))
			return (root);
		prev = head;
		if (!init_str(head))
			return (clean_str(root));
		prev->next = head;
	}
}

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;

	i = -1;
	while (src[++i] && i < len)
		dst[i] = src[i];
	while (i < len)
		dst[i++] = '\0';
	return (dst);
}

char			*str_lst_join(t_str *slst, size_t *len)
{
	char		*out;
	char		*cur;
	t_str		*head;

	if (!slst || !(out = (char*)malloc(sizeof(char) * *len)))
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
	slst = decode_format(ap, format);
	out = str_lst_join(slst, &len);
	va_end(ap);
	return (len);
}
