/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:27:40 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:32:16 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	checks for white-space characters.  In the "C" and  "POSIX"  lo‐
        cales,  these are: space, form-feed ('\f'), newline ('\n'), car‐
        riage return ('\r'), horizontal tab  ('\t'),  and  vertical  tab
        ('\v').
	
	RETURN VALUE
	The  values  returned  are  nonzero  if  the character c falls into the
        tested class, and zero if not.

*/

#include "../../include/libft.h"

int	ft_isspace(int c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
	{
		return (1);
	}
	return (0);
}
