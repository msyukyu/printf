/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:56:39 by dabeloos          #+#    #+#             */
/*   Updated: 2018/12/21 16:50:15 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*execute_op(va_list ap, const char *format)
{
	
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*output;

	va_start(ap, format);
	output = execute_op(ap, format);
	va_end(ap);
	return (ft_strlen(output));
}
