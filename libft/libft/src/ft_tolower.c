/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:17:37 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 14:18:50 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	These functions convert lowercase letters to uppercase, and vice versa.
	
	If c is an uppercase letter, tolower() returns its lowercase equivalent, 
	if a lowercase representation exists in the current locale.  Otherwise, 
	it returns c.
	
	If c is neither an unsigned char value nor EOF, the behavior of these 
	functions is undefined.
	
	RETURN VALUE
	The value returned is that of the converted letter, or c if the 
	conversion was not possible.
*/

#include "../../include/libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c = (char)c + 32;
	return (c);
}
