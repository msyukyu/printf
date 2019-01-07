/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:41:30 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/07 15:12:03 by dabeloos         ###   ########.fr       */
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
	char				*flags;
	int					mfw;
	unsigned char		period;
	char				type;
}						t_str;

#endif
