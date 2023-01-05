/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:41:37 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:46:06 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The strlcpy() and strlcat() functions copy and concatenate strings 
	respectively. They are designed to be safer, more consistent, and less 
	error prone replacements for strncpy(3) and strncat(3). Unlike those 
	functions, strlcpy() and strlcat() take the full size of the buffer 
	(not just the length) and guarantee to NUL-terminate the result (as 
	long as size is larger than 0 or, in the case of strlcat(), as long as 
	there is at least one byte free in dst). Note that a byte for the NULL 
	should be included in size. Also note that strlcpy() and strlcat() only 
	operate on true “C” strings.  This means that for strlcpy() src must be 
	NULL-terminated and for strlcat() both src and dst must be 
	NULL-terminated.

	The strlcat() function appends the NUL-terminated string src to the 
	end of dst. It will append at most size - strlen(dst) - 1 bytes, 
	NULL-terminating the result.

	RETURN VALUE
	The strlcpy() and strlcat() functions return the total length of the 
	string they tried to create. For strlcat() that means the initial length 
	of dst plus the length of src. While this may seem somewhat confusing, 
	it was done to make truncation detection simple.
*/

#include "../../include/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			n;
	size_t			dlen;
	char			*d;
	const char		*s;

	n = size;
	d = dst;
	s = src;
	while (*d && n--)
		d++;
	dlen = d - dst;
	n = size - dlen;
	if (n-- == 0)
		return ((dlen + ft_strlen(src)));
	while (*s)
	{
		if (n)
		{
			*d++ = *s;
			n--;
		}
		s++;
	}
	*d = 0;
	return ((dlen + (s - src)));
}
