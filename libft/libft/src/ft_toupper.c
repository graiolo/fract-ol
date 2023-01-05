/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:19:13 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 14:19:28 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	These functions convert lowercase letters to uppercase, and vice versa.
	
	If  c is a lowercase letter, toupper() returns its uppercase equivalent, 
	if an uppercase representation exists in the current locale. Otherwise, 
	it returns c.
	
	If c is neither an unsigned char value nor EOF, the behavior of these 
	functions is undefined.
	
	RETURN VALUE
	The value returned is that of the converted letter, or c if the 
	conversion was not possible.
*/

#include "../../include/libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = (char)c -32;
	return (c);
}
