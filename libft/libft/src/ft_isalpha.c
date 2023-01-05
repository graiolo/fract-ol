/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:45:53 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 10:46:24 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
    DESCRIPTION
    Checks  for an alphabetic character; in the standard "C" locale, it is 
    equivalent to (isupper(c) ||  islower(c)).   In  some  locales, there may 
    be additional characters for which isalpha() is true—letters which are 
    neither uppercase nor lowercase.

    RETURN VALUE
    The  values  returned  are  nonzero  if  the character c falls into the 
    tested class, and zero if not.
*/

#include "../../include/libft.h"

int	ft_isalpha(int val)
{
	if ((val >= 'A' && val <= 'Z') || (val >= 'a' && val <= 'z'))
		return (1024);
	return (0);
}
