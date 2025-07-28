/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_delete.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:19 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:19 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <stdint.h>

static t_gc	*gc_find_min(t_gc *node)
{
	while (node && node->left)
		node = node->left;
	return (node);
}

static t_gc	*gc_delete_node_single_or_leaf(t_gc *node)
{
	t_gc	*temp;

	if (node->left)
		temp = node->left;
	else
		temp = node->right;
	free(node);
	return (temp);
}

t_gc	*gc_delete_node(t_gc *root, void *ptr)
{
	t_gc	*temp;

	if (!root)
		return (NULL);
	if ((uintptr_t)ptr < (uintptr_t) root->ptr)
		root->left = gc_delete_node(root->left, ptr);
	else if ((uintptr_t)ptr > (uintptr_t) root->ptr)
		root->right = gc_delete_node(root->right, ptr);
	else
	{
		if (!root->left || !root->right)
			return (gc_delete_node_single_or_leaf(root));
		temp = gc_find_min(root->right);
		root->ptr = temp->ptr;
		root->right = gc_delete_node(root->right, temp->ptr);
	}
	root->height = 1 + gc_max(gc_get_height(root->left),
			gc_get_height(root->right));
	return (gc_balance_node(root));
}

void	gc_clear_postorder(t_gc *node)
{
	if (!node)
		return ;
	gc_clear_postorder(node->left);
	gc_clear_postorder(node->right);
	free(node->ptr);
	free(node);
}
