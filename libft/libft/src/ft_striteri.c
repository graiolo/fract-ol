/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:08:57 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/14 10:09:37 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	Applies the function ’f’ on each character of the string passed as 
	argument, passing its index as first argument. Each character is passed 
	by address to ’f’ to be modified if necessary.
	
	RETURN VALUE
	None.
*/

#include "../../include/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	cur;

	cur = 0;
	while (*s)
		f(cur++, s++);
}
