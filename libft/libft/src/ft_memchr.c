/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:03:20 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 13:04:02 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The memcmp() function compares the first n bytes (each interpreted as 
	unsigned char) of the memory areas s1 and s2.
	
	RETURN VALUE
	The  memcmp() function returns an integer less than, equal to, or 
	greater than zero if the first n bytes of s1 is found, respectively, 
	to be less than, to match, or be greater than the first n bytes of s2.
	
	For a nonzero return value, the sign is determined by the sign of the 
	difference between the first pair of bytes (interpreted as unsigned 
	char) that differ in s1 and s2.
	
	If n is zero, the return value is zero.
*/

#include "../../include/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		cur;
	char		*string;

	cur = 0;
	string = (void *)s;
	while (cur < n)
	{
		if (string[cur] == (char)c)
			return (&string[cur]);
		cur++;
	}
	return (NULL);
}
