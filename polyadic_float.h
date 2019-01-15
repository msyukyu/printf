/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyadic_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:13:25 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/15 14:17:08 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYADIC_FLOAT_H
# define POLYADIC_FLOAT_H

# define PF t_polyadic_float
# define ULL unsigned long long
# define PFBASE 1000000000000000000

typedef struct			s_polyadic_float
{
	char				sign;
	ULL					*i_part;
	ULL					*d_part;
	ULL					i_size;
	ULL					d_size;
}						t_polyadic_float;

#endif
