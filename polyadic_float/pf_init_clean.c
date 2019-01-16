/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:51:44 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/16 16:15:06 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

PFMNG			*init_pfmng(t_dbl *dbl)
{
	PFMNG		*mng;

	mng = (PFMNG*)malloc(sizeof(PFMNG));
	if (!mng)
		return (NULL);
	mng->sign = dbl->sign;
	if (!(mng->i_s = init_pf(0, NULL, NULL)))
	{
		free(mng);
		return (NULL);
	}
	mng->i_e = mng->i_s;
	mng->i_size = 1;
	if (!(mng->d_s = init_pf(0, mng->i_s, NULL)))
	{
		free(mng->i_s);
		free(mng);
		return (NULL);
	}
	mng->d_e = mng->d_s;
	mng->d_size = 1;
	mng->i_s->right = mng->d_s;
	return (mng);
}

PF				*init_pf(ULL inc, PF *left, PF *right)
{
	PF			*pf;

	pf = (PF*)malloc(sizeof(PF));
	if (!pf)
		return (NULL);
	pf->value = 0;
	pf->inc = inc;
	pf->shadow = 0;
	pf->inc_shadow = 0;
	pf->right = right;
	pf->left = left;
	return (pf);
}

void			clean_pfmng(PFMNG *mng)
{
	PF			*cur;
	PF			*prev;

	prev = mng->d_e;
	if (!prev)
		return ;
	cur = prev->left;
	while (prev)
	{
		free(prev);
		prev = cur;
		cur = prev->left;
	}
	free(mng);
}
