/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:52:52 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/12 11:53:04 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The strnstr() function locates the first occurrence of the 
	null-terminated string little in the string big, where not more than 
	len characters are searched. Characters that appear after a ‘\0’ 
	character are not searched. Since the strnstr() function is a FreeBSD 
	specific API, it should only be used when portability is not a concern.


	RETURN VALUE
	If little is an empty string, big is returned; if little occurs nowhere 
	in big, NULL is returned; otherwise a pointer to the first character of 
	the first occurrence of little is returned.
*/

#include "../../include/libft.h"

char	*ft_strncpy(char *s1, const char *s2, size_t n)
{
	size_t		cur;

	cur = 0;
	while (s2[cur] != '\0' && cur < n)
	{
		s1[cur] = s2[cur];
		cur++;
	}
	while (cur < n)
	{
		s1[cur] = '\0';
		cur++;
	}
	return (s1);
}
