/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:26 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:26 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	gc_get_height(t_gc *node)
{
	if (!node)
		return (0);
	return (node->height);
}

int	gc_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	gc_get_balance(t_gc *node)
{
	if (!node)
		return (0);
	return (gc_get_height(node->left) - gc_get_height(node->right));
}

t_gc	*gc_rotate_right(t_gc *root)
{
	t_gc	*new_root;
	t_gc	*temp;

	new_root = root->left;
	temp = new_root->right;
	new_root->right = root;
	root->left = temp;
	root->height = 1 + gc_max(gc_get_height(root->left),
			gc_get_height(root->right));
	new_root->height = 1 + gc_max(gc_get_height(new_root->left),
			gc_get_height(new_root->right));
	return (new_root);
}

t_gc	*gc_rotate_left(t_gc *root)
{
	t_gc	*new_root;
	t_gc	*temp;

	new_root = root->right;
	temp = new_root->left;
	new_root->left = root;
	root->right = temp;
	root->height = 1 + gc_max(gc_get_height(root->left),
			gc_get_height(root->right));
	new_root->height = 1 + gc_max(gc_get_height(new_root->left),
			gc_get_height(new_root->right));
	return (new_root);
}
