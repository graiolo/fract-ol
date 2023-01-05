/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:04:34 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 13:04:57 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The memcpy() function copies n bytes from memory area src to memory area 
	dest. The memory areas must not overlap. Use memmove(3) if the memory 
	areas do overlap.
	
	RETURN VALUE
	The memcpy() function returns a pointer to dest.
*/

#include "../../include/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!n)
		return (0);
	while (--n && *(const unsigned char *)s1 == *(const unsigned char *)s2)
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}
