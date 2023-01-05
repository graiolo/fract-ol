/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:01:50 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/14 16:08:06 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	Counts the number of nodes in a list.
	
	RETURN VALUE
	The length of the list.
*/

#include "../../include/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		len;
	t_list	*q;

	q = lst;
	len = 0;
	while (q)
	{
		q = q->next;
		len++;
	}
	return (len);
}
