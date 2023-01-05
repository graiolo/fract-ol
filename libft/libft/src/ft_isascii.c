/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:23:16 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:23:41 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION
    Checks whether c is a 7-bit unsigned char value that  fits  into the ASCII 
    character set.

    RETURN VALUE
    The  values  returned  are  nonzero  if  the character c falls into the 
    tested class, and zero if not.
*/

#include "../../include/libft.h"

int	ft_isascii(int val)
{
	if (val >= 0 && val <= 127)
		return (1);
	return (0);
}
