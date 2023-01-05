/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:27:46 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/12 09:28:18 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  strcpy()  function  copies the string pointed to by src, including
        the terminating null byte ('\0'), to the buffer  pointed  to  by  dest.
        The  strings  may  not overlap, and the destination string dest must be
        large enough to receive the copy.  Beware  of  buffer  overruns!   (See
        BUGS.)


	RETURN VALUE
	The strcpy() and strncpy() functions return a pointer to  the  destina‐
        tion string dest.

*/

#include "../../include/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	cur;

	cur = 0;
	while (src[cur])
	{
		dst[cur] = src[cur];
		cur++;
	}
	dst[cur] = 0;
	return (dst);
}
