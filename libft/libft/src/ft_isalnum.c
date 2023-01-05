/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:43:16 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 10:44:05 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION
    Checks for an alphanumeric character; it is equivalent to (isalpha(c) || 
    isdigit(c)).

    RETURN VALUE
    The  values  returned  are  nonzero  if  the character c falls into the 
    tested class, and zero if not.
*/

#include "../../include/libft.h"

int	ft_isalnum(int val)
{
	if (ft_isalpha(val) || ft_isdigit(val))
		return (8);
	return (0);
}
