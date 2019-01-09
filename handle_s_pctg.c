/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_s_pctg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 20:33:41 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/09 20:34:18 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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

	//type %
	//all valid
size_t			handle_pctg(va_list ap, t_str *head, t_mrk *mrk)
{
	return (0);
}
