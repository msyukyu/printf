/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_init_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:51:44 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/15 18:06:27 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

PFMNG			*init_pfmng()
{
	PFMNG		*mng;

	mng = (PFMNG*)malloc(sizeof(PFMNG));
	if (!mng)
		return (NULL);
	mng->sign = 1;
	mng->i_s = NULL;
	mng->i_e = NULL;
	mng->i_size = 0;
	mng->d_s = NULL;
	mng->d_e = NULL;
	mng->d_size = 0;
	return (mng);
}

PF				*init_pf(PFMNG *mng)
{
	PF			*pf;

	pf = (PF*)malloc(sizeof(PF));
	if (!pf)
		return (NULL);
	pf->value = 0;
	pf->prev = NULL;
	pf->next = NULL;
	pf->manager = mng;
	return (pf);
}


