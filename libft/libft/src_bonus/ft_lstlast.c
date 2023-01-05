/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:09:04 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/14 16:26:21 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	Returns the last node of the list.
	
	RETURN VALUE
	Last node of the list.
*/

#include "../../include/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*q;
	t_list	*p;

	q = lst;
	if (!q)
		return (NULL);
	while (q)
	{
		p = q;
		q = q->next;
	}
	return (p);
}
