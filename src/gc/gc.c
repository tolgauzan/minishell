/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:29 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:29 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static t_gc	**gc_get_root(void)
{
	static t_gc	*root = NULL;

	return (&root);
}

void	*gc_safe(void *ptr)
{
	t_gc	**root;

	if (!ptr)
		shutdown(1);
	root = gc_get_root();
	*root = gc_insert(*root, ptr);
	if (!(*root))
	{
		free(ptr);
		shutdown(1);
	}
	return (ptr);
}

void	*gc_malloc(size_t size)
{
	return (gc_safe(malloc(size)));
}

void	gc_free(void *ptr)
{
	t_gc	**root;

	if (!ptr)
		return ;
	root = gc_get_root();
	*root = gc_delete_node(*root, ptr);
	free(ptr);
}

void	gc_free_all(void)
{
	t_gc	**root;

	root = gc_get_root();
	gc_clear_postorder(*root);
	*root = NULL;
}
