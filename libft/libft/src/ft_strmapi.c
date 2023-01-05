/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:00:53 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/14 10:01:54 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	Applies the function ’f’ to each character of the string ’s’, and 
	passing its index as first argument to create a new string (with 
	malloc(3)) resulting from successive applications of ’f’.

	RETURN VALUE
	The string created from the successive applications of ’f’. Returns 
	NULL if the allocation fails.
*/

#include "../../include/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	cur;
	char			*str;

	cur = 0;
	str = (char *)ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!str)
		return (NULL);
	while (s[cur])
	{
		str[cur] = f(cur, s[cur]);
		cur++;
	}
	return (str);
}
