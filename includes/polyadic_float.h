/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyadic_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:13:25 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/15 14:49:37 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYADIC_FLOAT_H
# define POLYADIC_FLOAT_H

# define PF struct s_polyadic_float
# define ULL unsigned long long
# define PFBASE (unsigned long long)1000000000000000000
# define PFMNG struct s_polyadic_float_manager

typedef struct			s_polyadic_float
{
	ULL					value;
	PF					*prev;
	PF					*next;
	PFMNG				*manager;
}						t_polyadic_float;

typedef struct			s_polyadic_float_manager
{


}						t_polyadic_float_manager;

#endif
