/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   polyadic_float.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:13:25 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/16 17:03:25 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POLYADIC_FLOAT_H
# define POLYADIC_FLOAT_H

# define PF struct s_polyadic_float
# define ULL unsigned long long
# define PFBASE (unsigned long long)1000000000000000000
# define PFMNG struct s_polyadic_float_manager

# include <stdlib.h>

typedef struct			s_frac
{
	ULL					fraction;
	unsigned int		left_offset;
}						t_frac;

typedef struct			s_dbl
{
	char				sign;
	unsigned char		normalized;
	int					exponent;
	t_frac				fraction;
}						t_dbl;

typedef struct			s_polyadic_float
{
	ULL					value;
	ULL					shadow;
	ULL					inc_shadow;
	ULL					inc;
	PF					*right;
	PF					*left;
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

unsigned char			*store_ldouble_bits(long double in);
unsigned char			*store_double_bits(double in);

char					extract_float_sign(unsigned char *bits, size_t size);
int						extract_float_exponent(size_t len, size_t offset,
							unsigned char *bits, size_t size);
unsigned char			extract_ldouble_normalized(size_t offset,
							unsigned char *bits, size_t size);
t_frac					extract_float_fraction(size_t len, size_t offset,
							unsigned char *bits, size_t size);

t_dbl					*extract_ldouble_infos(long double in);
t_dbl					*extract_double_infos(double in);

PF						*add_right_shadow(ULL inc_shadow, PFMNG *mng);

PFMNG					*init_pfmng(t_dbl *dbl);
PF						*init_pf(ULL inc, PF *left, PF *right);

PFMNG					*pf_boot(long double in);
void					decode_fraction(t_dbl *dbl, PFMNG *mng);
unsigned char			shift_shadow(PFMNG *mng, PF *cur);
void					increment_shadow(PFMNG *mng, PF *cur);

#endif
