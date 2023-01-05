/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:33:10 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:33:19 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  memchr()  function scans the initial n bytes of the memory area 
	pointed to by s for the first instance of c. Both c and the bytes of the 
	memory area pointed to by s are interpreted as unsigned char.
    
	RETURN VALUE
	The memchr() and memrchr() functions return a pointer to the matching 
	byte or NULL if the character does not occur in the given memory area.
*/

#include "../../include/libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	char	*c1;
	char	*c2;
	size_t	cur;

	if (s1 == s2 || n == 0)
		return (s1);
	cur = 0;
	c1 = (char *)s1;
	c2 = (char *)s2;
	while (cur < n)
	{
		c1[cur] = c2[cur];
		if (c1[cur] == c)
			return (c1 + cur + 1);
		cur++;
	}
	return (NULL);
}
