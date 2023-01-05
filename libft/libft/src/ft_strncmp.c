/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:11:58 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 14:12:57 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  strcmp()  function  compares  the  two  strings  s1 and s2. The 
	locale is not taken into account (for a locale-aware comparison, see 
	strcoll(3)).  It returns an integer less than, equal to, or greater 
	than zero if s1 is found, respectively, to be less than, to match, or 
	be greater than s2.
	
	The strncmp() function is similar, except it compares only the first 
	(at most) n bytes of s1 and s2.

	RETURN VALUE
	The strcmp() and strncmp() functions return an integer less than, 
	equal to, or greater than zero if s1 (or the first n bytes thereof) 
	is found, respectively, to be less than, to match, or be greater than 
	s2.
*/

#include "../../include/libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (*s1 == *s2 && --n && *s1)
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
