/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:11:10 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 14:11:31 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The strlen() function calculates the length of the string pointed to by 
	s, excluding the terminating null byte ('\0').

	RETURN VALUE
	The strlen() function returns the number of bytes in the string pointed 
	to by s.
*/

#include "../../include/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	cur;

	cur = 0;
	while (*(str++))
		cur++;
	return (cur);
}
