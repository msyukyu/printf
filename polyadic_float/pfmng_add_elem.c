/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pfmng_add_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 16:15:57 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/16 16:57:16 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

PF				*add_right_shadow(ULL inc_shadow, PFMNG *mng)
{
	PF				*new;

	if(!(new = init_pf(0, mng->d_e, NULL)))
		return (NULL);
	++mng->d_size;
	mng->d_e->right = new;
	new->inc_shadow = inc_shadow;
	return (new);
}
