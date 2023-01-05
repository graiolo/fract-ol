/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:22:59 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 14:23:47 by graiolo          ###   ########.fr       */
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
	NUL-terminated and for strlcat() both src and dst must be 
	NUL-terminated.

	The strlcpy() function copies up to size - 1 characters from the 
	NULL-terminated string src to dst, NULL-terminating the result.

	RETURN VALUE
	The strlcpy() and strlcat() functions return the total length of the 
	string they tried to create. For strlcpy() that means the length of src. 
	While this may seem somewhat confusing, it was done to make truncation 
	detection simple.
*/

#include "../../include/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	n;

	n = ft_strlen(src);
	if (size == 0)
		return (n);
	while (--size && *src)
		*dst++ = *src++;
	*dst = 0;
	return (n);
}
