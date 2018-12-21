/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:41:30 by dabeloos          #+#    #+#             */
/*   Updated: 2018/12/21 16:45:07 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef char			*(*operation)(char *, int, ...);

typedef struct			s_op
{
	char				*text;
	operation			op;
	struct s_op			*next;
}						t_op;

char					*execute_op(va_list ap, const char *format);

int						ft_strlen(char *str);

#endif
