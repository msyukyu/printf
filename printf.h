/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:41:30 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/09 20:54:22 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>

typedef struct			s_str
{
	char				*txt;
	size_t				len;
	struct s_str		*next;
	unsigned char		is_raw;
}						t_str;

typedef struct			s_mrk
{
	char				*flags;
	size_t				len_flags;
	unsigned char		arg_mfw;
	size_t				mfw;
	unsigned char		arg_precision;
	size_t				precision;
	char				*len_modif;
	size_t				len_len_modif;
	char				type;
}						t_mrk;

void					sort_char(char *tab, size_t s, size_t e);
unsigned char			search_flag(char flag, t_mrk *mrk);

t_str					*init_str(t_str *s);
t_str					*clean_str(t_str *s);
void					init_mrk(t_mrk *m);

size_t					size_length_modifier(char *in);
unsigned char			is_flag(char in);
unsigned char			is_number(char in);
char					*ft_strncpy(char *dst, const char *src, size_t len);
unsigned int			ft_atoui_limited(const char *str);

char					*inspect_flags(char *cur, t_mrk *mrk);
char					*inspect_mfw(char *cur, t_mrk *mrk);
char					*inspect_precision(char *cur, t_mrk *mrk);
char					*inspect_length_modifier(char *cur, t_mrk *mrk);
size_t					inspect_arg_type(va_list ap, char *cur, t_str *head,
							t_mrk *mrk);

size_t					handle_c(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_s(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_p(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_d(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_i(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_o(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_u(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_x(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_x_maj(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_f(va_list ap, t_str *head, t_mrk *mrk);
size_t					handle_pctg(va_list ap, t_str *head, t_mrk *mrk);

char					*copy_raw_ignore(char *cur, t_str *head, size_t start,
							size_t *len);
char					*copy_raw(char *cur, t_str *head, size_t *len);
char					*decode_identifier(va_list ap, char *cur, t_str *head,
							size_t *len);
t_str					*decode_format(va_list ap, const char *format,
							size_t *len);

char					*str_lst_join(t_str *slst, size_t len);
int						ft_printf(const char *format, ...);

#endif
