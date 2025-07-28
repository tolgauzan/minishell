/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:49:22 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:49:22 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mappedlist;
	t_list	*node;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	mappedlist = NULL;
	while (lst != NULL)
	{
		new_content = f(lst->content);
		node = ft_lstnew(new_content);
		if (node == NULL)
		{
			del(new_content);
			ft_lstclear(&mappedlist, del);
			return (NULL);
		}
		ft_lstadd_back(&mappedlist, node);
		lst = lst->next;
	}
	return (mappedlist);
}
