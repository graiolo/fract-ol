/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_rvs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:36:34 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:37:07 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The memcpy_rvs() function copies n bytes from memory area src to memory area 
	dest. The memory areas must not overlap. Use memmove(3) if the memory 
	areas do overlap.
	
	RETURN VALUE
	The memcpy() function returns a pointer to dest.
*/

#include "../../include/libft.h"

void	*ft_memcpy_rvs(void *dest, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	if (len == 0 || dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (len--)
		d[len] = s[len];
	return (dest);
}
