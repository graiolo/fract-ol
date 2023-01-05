/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:42:02 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/11 10:42:50 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	The  bzero()  function  erases  the  data in the n bytes of the memory 
	starting at the location pointed to by s, by writing zeros (bytes 
	containing '\0') to that area.
	
	RETURN VALUE
	None.
*/

#include "../../include/libft.h"

void	ft_bzero(void *s, size_t len)
{
	ft_memset(s, 0, len);
}
