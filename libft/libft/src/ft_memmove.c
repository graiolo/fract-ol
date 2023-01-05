/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:38:08 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:38:32 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  memmove() function copies n bytes from memory area src to memory 
	area dest. The memory areas may overlap: copying takes place as though 
	the bytes in src are first copied into a temporary array that does not 
	overlap src or dest, and the bytes are then copied from the temporary 
	array to dest.
	
	RETURN VALUE
	The memmove() function returns a pointer to dest.
*/

#include "../../include/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (dest < src)
		ft_memcpy(dest, src, len);
	if (dest > src)
		ft_memcpy_rvs(dest, src, len);
	return (dest);
}
