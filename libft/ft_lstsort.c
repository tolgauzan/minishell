/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:49:31 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:49:31 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstsplit(t_list *src, t_list **front, t_list **back)
{
	t_list	*slow;
	t_list	*fast;

	if (!src || !src->next)
	{
		*front = src;
		*back = NULL;
		return ;
	}
	slow = src;
	fast = src->next;
	while (fast)
	{
		fast = fast->next;
		if (fast)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}
	*front = src;
	*back = slow->next;
	slow->next = NULL;
}

void	ft_lstsort(t_list **lst, int (*cmp)(void *, void *))
{
	t_list	*head;
	t_list	*front;
	t_list	*back;

	if (!lst || !(*lst) || !(*lst)->next)
		return ;
	head = *lst;
	ft_lstsplit(head, &front, &back);
	ft_lstsort(&front, cmp);
	ft_lstsort(&back, cmp);
	*lst = front;
	ft_lstsorted_merge(lst, back, cmp);
}
