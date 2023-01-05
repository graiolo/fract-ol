/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:05:15 by graiolo           #+#    #+#             */
/*   Updated: 2022/12/22 14:05:18 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  atof() function converts the initial portion of the string pointed to 
	by nptr to double.
	
	RETURN VALUE
	The converted value.
*/

#include "../../include/libft.h"

double	ft_atof(char *s)
{
	double	nb;
	double	power;
	int		sign;
	int		i;

	sign = 1;
	nb = 0.0;
	power = 1.0;
	i = 0;
	if (s[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
		nb = 10.0 * nb + (s[i++] - '0');
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
	{
		nb = 10.0 * nb + (s[i] - '0');
		power *= 10.0;
		i++;
	}
	return (sign * nb / power);
}
