/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:07:25 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 13:10:58 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The strdup() function returns a pointer to a new string which is a 
	duplicate of the string s. Memory for the new string is obtained with 
	malloc(3), and can be freed with free(3).

	RETURN VALUE
	On success, the strdup() function returns a pointer to the duplicated 
	string. It returns NULL if insufficient memory was available, with 
	errno set to indicate the cause of the error.
*/

#include "../../include/libft.h"

char	*ft_strdup(const char *s)
{
	unsigned char	s_len;
	char			*dest;

	s_len = ft_strlen(s);
	dest = (char *)malloc(++s_len);
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s, s_len);
	return (dest);
}
