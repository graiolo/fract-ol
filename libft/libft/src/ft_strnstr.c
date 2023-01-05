/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:13:47 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 14:16:07 by graiolo          ###   ########.fr       */
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

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	cur2;
	size_t	cur;

	cur2 = 0;
	cur = 0;
	if (!ft_strlen(little))
		return ((char *)big);
	len = ft_min(len, ft_strlen(big));
	while (big[cur] && &big[cur] != &big[len])
	{
		if (big[cur] != little[cur2])
		{
			cur -= cur2;
			cur2 = 0;
		}
		else
			cur2++;
		if (!little[cur2])
			return ((char *)(&big[cur - (ft_strlen(little) - 1)]));
		cur++;
	}
	return (NULL);
}
