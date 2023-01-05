/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:24:15 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 12:24:51 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION
    Checks for a digit (0 through 9).

    RETURN VALUE
    The  values  returned  are  nonzero  if  the character c falls into the 
    tested class, and zero if not.
*/

#include "../../include/libft.h"

int	ft_isdigit(int val)
{
	if (val >= '0' && val <= '9')
		return (2048);
	return (0);
}
