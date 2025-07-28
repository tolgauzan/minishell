/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:23 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:23 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdint.h>
#include <stdlib.h>

static t_gc	*gc_new_node(void *ptr)
{
	t_gc	*node;

	node = (t_gc *)malloc(sizeof(t_gc));
	if (!node)
		return (NULL);
	node->ptr = ptr;
	node->left = NULL;
	node->right = NULL;
	node->height = 1;
	return (node);
}

t_gc	*gc_balance_node(t_gc *node)
{
	int	balance;

	balance = gc_get_balance(node);
	if (balance > 1)
	{
		if (gc_get_balance(node->left) >= 0)
			return (gc_rotate_right(node));
		else
		{
			node->left = gc_rotate_left(node->left);
			return (gc_rotate_right(node));
		}
	}
	else if (balance < -1)
	{
		if (gc_get_balance(node->right) <= 0)
			return (gc_rotate_left(node));
		else
		{
			node->right = gc_rotate_right(node->right);
			return (gc_rotate_left(node));
		}
	}
	return (node);
}

t_gc	*gc_insert(t_gc *root, void *ptr)
{
	if (!root)
		return (gc_new_node(ptr));
	if ((uintptr_t)ptr < (uintptr_t)root->ptr)
		root->left = gc_insert(root->left, ptr);
	else if ((uintptr_t)ptr > (uintptr_t)root->ptr)
		root->right = gc_insert(root->right, ptr);
	else
		return (root);
	root->height = 1 + gc_max(gc_get_height(root->left),
			gc_get_height(root->right));
	return (gc_balance_node(root));
}
