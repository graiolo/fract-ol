/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:33:57 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:35:35 by graiolo          ###   ########.fr       */
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

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	if (len == 0 || dest == src)
		return (dest);
	d = (char *)dest;
	s = (const char *)src;
	while (--len)
		*d++ = *s++;
	*d = *s;
	return (dest);
}
