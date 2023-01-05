/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graiolo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 16:54:38 by graiolo           #+#    #+#             */
/*   Updated: 2022/10/14 17:34:39 by graiolo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	DESCRIPTION
	Deletes and frees the given node and every successor of that node, using 
	the function ’del’ and free(3). Finally, the pointer to the list must 
	be set to NULL.
	
	RETURN VALUE
	None.
*/

#include "../../include/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*q;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		q = *lst;
		*lst = q->next;
		free(q);
	}
}
