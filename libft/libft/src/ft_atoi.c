/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:38:24 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 10:41:04 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  atoi() function converts the initial portion of the string pointed to 
	by nptr to int.  The behavior is the same as strtol(nptr, NULL, 10); 
	except that atoi() does not detect errors.
	
	RETURN VALUE
	The converted value.
*/

#include "../../include/libft.h"

int	ft_atoi(const char *nptr)
{
	int	sing;
	int	num;

	num = 0;
	sing = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sing *= -1;
		nptr++;
	}
	while (*nptr > 47 && *nptr < 58)
		num = num * 10 + (*nptr++ - 48);
	return (num * sing);
}
