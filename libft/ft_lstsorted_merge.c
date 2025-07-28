/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsorted_merge.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:49:36 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:49:36 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstsorted_merge(t_list **lst1, t_list *lst2,
		int (*cmp)(void *, void *))
{
	t_list	*curr;
	t_list	*insert;

	if (!lst1 || !cmp)
		return ;
	curr = *lst1;
	while (lst2)
	{
		insert = lst2;
		lst2 = lst2->next;
		if (!curr || cmp(curr->content, insert->content) > 0)
		{
			insert->next = curr;
			*lst1 = insert;
			curr = insert;
		}
		else
		{
			while (curr->next && cmp(curr->next->content, insert->content) < 0)
				curr = curr->next;
			insert->next = curr->next;
			curr->next = insert;
		}
	}
}
