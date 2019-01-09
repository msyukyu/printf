/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/09 19:46:46 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_swap_char(char *a, char *b)
{
	char	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void			ft_sort_char(char *tab, size_t s, size_t e)
{
	size_t		es;
	size_t		ee;
	size_t		sg;

	if (tab == NULL)
		return ;
	es = s;
	ee = s;
	sg = e;
	while (ee < sg)
	{
		if (tab[ee] < tab[es])
			ft_swap_char(tab + ee++, tab + es++);
		else if (tab[ee] == tab[es])
			++ee;
		else
			ft_swap_char(tab + ee, tab + --sg);
	}
	if (s < es - 1)
		ft_sort_char(tab, s, es);
	if (sg < e - 1)
		ft_sort_char(tab, sg, e);
}

unsigned char	search_char(char flag, char *tab, size_t s, size_t e)
{
	size_t		i;

	if (s < e)
	{
		i = (e - s) / 2;
		if (tab[i] == flag)
			return (1);
		else if (tab[i] < flag)
			return (search_char(flag, tab, i + 1, e));
		else
			return (search_char(flag, tab, s, i));
	}
	else
		return (0);
}

unsigned char	search_flag(char flag, t_mrk *mrk)
{
	return (search_char(flag, mrk->flags, 0, mrk->len_flags));
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
		ft_sort_char(cur, 0, pos);
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

	//type c
	//invalid flags : 0+ #
	//invalid precision
	//invalid modifier : all
size_t	handle_c(va_list ap, t_str *head, t_mrk *mrk)
{
	//size_t
	//min : mfw
	//else : number size
	//- : left justified
	head->txt = uint_tostr(va_arg(ap, unsigned int), head, mrk);
	if (!head->txt)
		return (0);
	head->is_raw = 0;
	if (search_flag('-', mrk))
		left_justify(' ', head, mrk);
	else
		right_justify(' ', head, mrk);
	return ((head->txt) ? head->len : 0);
}
	//type s
	//invalids flags : 0+ #
	//invalid modifier : all
size_t			handle_s(va_list ap, t_str *head, t_mrk *mrk)
{
	//char *
	//max : precision
	//min : mfw
	//else : string size
	//- : left justified
	return (0);
}
	//type p
	//invalid flags : 0+ #
	//invalid precision
	//invalid modifier : all
size_t			handle_p(va_list ap, t_str *head, t_mrk *mrk)
{
	//uintmax_t
	//min : mfw
	//else : number size
	//- : left justified
	return (0);
}
	//type d
	//invalid flags : #
	//invalid modifier : L
size_t			handle_d(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
	//type i
	//invalid flags : #
	//invalid modifier : L
size_t			handle_i(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
	//type o
	//invalid flags : + 
	//invalid modifier : L
size_t			handle_o(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
	//type u
	//invalid flags : + #
	//invalid modifier : L
size_t			handle_u(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
	//type x
	//invalid flags : + 
	//invalid modifier : L
size_t			handle_x(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
	//type X
	//invalid flags : + 
	//invalid modifier : L
size_t			handle_x_maj(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
	//type f
	//invalid modifier : ll h hh
size_t			handle_f(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
	//type %
	//all valid
size_t			handle_pctg(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
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

char			*copy_raw_ignore(char *cur, t_str *head, size_t start,
		size_t *len)
{
	while (cur[++start] && cur[start] != '%')
		;
	head->txt = cur;
	head->len = start;
	*len += start;
	return (cur + start);
}

char			*copy_raw(char *cur, t_str *head, size_t *len)
{
	return (copy_raw_ignore(cur, head, -1, len));
}

char			*decode_identifier(va_list ap, char *cur, t_str *head,
		size_t *len)
{
	t_mrk		mrk;
	char		*base_cur;

	base_cur = cur;
	init_mrk(&mrk);
	cur = inspect_flags(cur + 1, &mrk);
	cur = inspect_mfw(cur, &mrk);
	cur = inspect_precision(cur, &mrk);
	cur = inspect_length_modifier(cur, &mrk);
	cur = ((*len += inspect_arg_type(ap, cur, head, &mrk))) ? cur + 1 : NULL;
	if (!cur)
		return (copy_raw_ignore(base_cur, head, 0, len));
	else
		return (cur);
}

t_str			*decode_format(va_list ap, const char *format, size_t *len)
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
			cur = decode_identifier(ap, cur, head, len);
		else
			cur = copy_raw(cur, head, len);
		if (!(*cur))
			return (root);
		prev = head;
		if (!init_str(head))
			return (clean_str(root));
		prev->next = head;
	}
}

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
