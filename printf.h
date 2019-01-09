/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:41:30 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/09 15:20:51 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//typedef char			*(*operation)(char *, int, ...);

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
	unsigned int		mfw;
	unsigned char		arg_precision;
	unsigned int		precision;
	char				*len_modif;
	size_t				len_len_modif;
	char				type;
}						t_mrk;

#endif
