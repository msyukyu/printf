/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:48:35 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/11 14:36:14 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void				swap_char(char *a, char *b)
{
	char	tmp;

	if (a == NULL || b == NULL)
		return ;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void					sort_char(char *tab, size_t s, size_t e)
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
			swap_char(tab + ee++, tab + es++);
		else if (tab[ee] == tab[es])
			++ee;
		else
			swap_char(tab + ee, tab + --sg);
	}
	if (s + 1 < es)
		sort_char(tab, s, es);
	if (sg + 1 < e)
		sort_char(tab, sg, e);
}

static unsigned char	search_char(char flag, char *tab, size_t s, size_t e)
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

unsigned char			search_flag(char flag, t_mrk *mrk)
{
	return (search_char(flag, mrk->flags, 0, mrk->len_flags));
}
