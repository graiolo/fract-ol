/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:27:14 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/14 16:44:33 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	Adds the node ’new’ at the end of the list.
	
	RETURN VALUE
	None.
*/

#include "../../include/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*q;
	t_list	*p;

	q = *lst;
	if (!lst || !new)
		return ;
	if (!q)
	{
		*lst = new;
		return ;
	}
	while (q)
	{
		p = q;
		q = q->next;
	}
	p->next = new;
}
