/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 09:56:42 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/12 09:56:51 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  strcat() function appends the src string to the dest string, over‐
        writing the terminating null byte ('\0') at the end of dest,  and  then
        adds  a  terminating  null  byte.  The strings may not overlap, and the
        dest string must have enough space for the  result.   If  dest  is  not
        large  enough, program behavior is unpredictable; buffer overruns are a
        favorite avenue for attacking secure programs.

	RETURN VALUE
	 The strcat() and strncat() functions return a pointer to the  resulting
        string dest.
*/

#include "../../include/libft.h"

char	*ft_strcat(char *dst, const char *src)
{
	size_t	dst_len;
	size_t	i;

	dst_len = ft_strlen(dst);
	i = 0;
	while (src[i])
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst);
}
