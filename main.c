/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabeloos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 14:51:44 by dabeloos          #+#    #+#             */
/*   Updated: 2019/01/08 17:08:28 by dabeloos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include <stdio.h>

int		main(void)
{
	printf("%-%   "); //flags
	printf("%0%   ");
	printf("%+%   ");
	printf("% %   ");
	printf("%#%   ");
	printf("%l%   "); //modifier
	printf("%ll%   ");
	printf("%L%   ");
	printf("%hh%   ");
	printf("%h%   ");
	printf("%5%   "); //mfw
	printf("%.2%   "); //precision

	return (0);
}
