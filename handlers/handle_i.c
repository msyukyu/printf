/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 16:59:24 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/12 16:09:33 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

//type i
//invalid flags : #
//invalid modifier : L
size_t			handle_i(va_list ap, t_str *head, t_mrk *mrk)
{
	return (handle_d(ap, head, mrk));
}