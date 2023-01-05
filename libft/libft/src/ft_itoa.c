/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:11:36 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/13 16:12:26 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	Allocates (with malloc(3)) and returns a string representing the 
	integer received as an argument. Negative numbers must be handled.
	
	RETURN VALUE
	The string representing the integer. NULL if the allocation fails.
*/

#include "../../include/libft.h"

static	int	ft_get_len(int n)
{
	int	len;

	len = 0;
	if (!n)
		return (1);
	if (n < 0)
		++len;
	while (n != 0)
	{
		++len;
		n = n / 10;
	}
	return (len);
}

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	*ft_itoa(int n)
{
	char	*s_out;
	int		len;

	len = ft_get_len(n);
	s_out = malloc(sizeof(char) * (len + 1));
	if (!s_out)
		return (NULL);
	s_out[len] = '\0';
	if (n < 0)
		s_out[0] = '-';
	else if (n == 0)
		s_out[0] = '0';
	while (n != 0)
	{
		--len;
		s_out[len] = ft_abs((n % 10)) + '0';
		n /= 10;
	}
	return (s_out);
}
