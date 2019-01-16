/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyadic_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:13:25 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/16 13:58:14 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYADIC_FLOAT_H
# define POLYADIC_FLOAT_H

# define PF struct s_polyadic_float
# define ULL unsigned long long
# define PFBASE (unsigned long long)1000000000000000000
# define PFMNG struct s_polyadic_float_manager

typedef struct			s_dbl
{
	char				sign;
	unsigned char		normalized;
	int					exponent;
	ULL					fraction;
}						t_dbl;

typedef struct			s_polyadic_float
{
	ULL					value;
	ULL					shadow;
	ULL					inc;
	PF					*prev;
	PF					*next;
	PFMNG				*manager;
}						t_polyadic_float;

typedef struct			s_polyadic_float_manager
{
	char				sign;
	PF					*i_s;
	PF					*i_e;
	ULL					i_size;
	PF					*d_s;
	PF					*d_e;
	ULL					d_size;
}						t_polyadic_float_manager;

t_dbl					*extract_ldouble_infos(long double in);
t_dbl					*extract_double_infos(double in);

PFMNG					*init_pfmng(t_dbl *dbl);
PF						*init_pf(ULL inc);

PFMNG					*pf_boot(long double in);

#endif
