/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/13 20:21:59 by dabeloos         ###   ########.fr       */
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
	long double d = 1.0;
	long double e = 2.0;
	long double f = -2.0;
	long double g = 3.0;
	long double h = 0.5;
	long double i = (long double)0.0 * ((long double)-5.0 / (long double)0.0);
	double a = 0.0 * (5.0 / 0.0);
	ft_printf("%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n%Lf\n", d, e, f, g, h);
	ft_printf("%f\n%f\n%f\n%f\n%f\n%f\n", 1.0, 2.0, -2.0, 3.0, 0.5, a);
	//printf("%Lf", (long double)0.0 * ((long double)-5.0 / (long double)0.0));
	
	//a gerer
	//ft_printf("%.d", 0);
	//printf("\n%.d", 0);

	//a gerer (afficher l'espace meme sans le 0)
	//ft_printf("% .d bonjour", 0);
	//printf("\n% .d bonjour", 0);

	//en cas d'erreur, renvoyer -1
	return (0);
}
