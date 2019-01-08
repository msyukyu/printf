/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/08 17:08:27 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

unsigned int	ft_atoui_limited(const char *str)
{
	unsigned int		result;
	size_t		i;
	unsigned int		tmp;

	result = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = result;
		result = result * 10 + str[i++] - '0';
		if (result < tmp)
			return (~((unsigned int)0));
	}
	return (result);
}

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
	m->arg_mfw = 0;
	m->mfw = 0;
	m->arg_precision = 0;
	m->precision = 0;
	m->len_modif = NULL;
	m->len_len_modif = 0;
	m->type = 0;
}

size_t			size_length_modifier(char *in)
{
	size_t		pos;
	char		m;

	pos = -1;
	m = in[++pos];
	if (m == 'l' || m == 'h' || m == 'L')
	{
		m = in[++pos];
		if (m == in[pos - 1] && (m == 'h' || m == 'l'))
			++pos;
	}
	return (pos);
}

unsigned char	is_flag(char in)
{
	return (in == '-' || in == '0' || in == '+' || in == ' ' || in == '#');
}

unsigned char	is_number(char in)
{
	return (in >= '0' && in <= '9');
}

char			*inspect_flags(char *cur, t_mrk *mrk)
{
	size_t		pos;

	pos = -1;
	while (is_flag(cur[++pos]))
		;
	if (pos > 0)
	{
		mrk->flags = cur;
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

//sort flags, create search method
unsigned char	check_type(t_mrk *mrk)
{
	//type c
	//invalid flags : 0+ #
	//invalid precision
	//invalid modifier : all
	//
	//type s
	//invalids flags : 0+ #
	//invalid modifier : all
	//
	//type p
	//invalid flags : 0+ #
	//invalid precision
	//invalid modifier : all
	//
	//type d
	//invalid flags : #
	//invalid modifier : L
	//
	//type i
	//invalid flags : #
	//invalid modifier : L
	//
	//type o
	//invalid flags : + 
	//invalid modifier : L
	//
	//type u
	//invalid flags : + #
	//invalid modifier : L
	//
	//type x
	//invalid flags : + 
	//invalid modifier : L
	//
	//type X
	//invalid flags : + 
	//invalid modifier : L
	//
	//type f
	//invalid modifier : ll h hh
	//
	//type %
	//all valid
}

char			*at_dispatch(char *cur, t_mrk *mrk,
		unsigned char (*f)(t_mrk*))
{
	mrk->type = *cur;
	return ((f(mrk)) ? cur + 1 : NULL);
}

char			*inspect_arg_type(char *cur, t_mrk *mrk)
{
	if (*cur == 'c')
		return (at_dispatch(cur, mrk, check_type_c));
	if (*cur == 's')
		return (at_dispatch(cur, mrk, check_type_s));
	if (*cur == 'p')
		return (at_dispatch(cur, mrk, check_type_p));
	if (*cur == 'd')
		return (at_dispatch(cur, mrk, check_type_d));
	if (*cur == 'i')
		return (at_dispatch(cur, mrk, check_type_i));
	if (*cur == 'o')
		return (at_dispatch(cur, mrk, check_type_o));
	if (*cur == 'u')
		return (at_dispatch(cur, mrk, check_type_u));
	if (*cur == 'x')
		return (at_dispatch(cur, mrk, check_type_x));
	if (*cur == 'X')
		return (at_dispatch(cur, mrk, check_type_x_maj));
	if (*cur == 'f')
		return (at_dispatch(cur, mrk, check_type_f));
	if (*cur == '%')
		return (at_dispatch(cur, mrk, check_type_pctg));
	return (NULL);
}

char			*decode_identifier(va_list ap, char *cur, t_str *head)
{
	t_mrk		mrk;
	char		*base_cur;

	base_cur = cur;
	init_mrk(&mrk);
	cur = inspect_flags(cur + 1, &mrk);
	cur = inspect_mfw(cur, &mrk);
	cur = inspect_precision(cur, &mrk);
	cur = inspect_length_modifier(cur, &mrk);
	cur = inspect_arg_type(cur, &mrk);
	return (cur + pos);
}

char			*copy_raw(char *cur, t_str *head)
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
			cur = decode_identifier(ap, cur, head);
		else
			cur = copy_raw(cur, head);
		if (!(*cur))
			return (root);
		prev = head;
		if (!init_str(head))
			return (clean_str(root));
		prev->next = head;
	}
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
