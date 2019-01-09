/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_p_o_x_xmaj.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:34:29 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/09 20:35:35 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

	//type o
	//invalid flags : + 
	//invalid modifier : L
size_t			handle_o(va_list ap, t_str *head, t_mrk *mrk)
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
