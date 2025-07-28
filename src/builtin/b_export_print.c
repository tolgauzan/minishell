/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_export_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:51:49 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:51:49 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static void	free_shallow_list(t_list *node)
{
	t_list	*next;

	while (node)
	{
		next = node->next;
		gc_free(node);
		node = next;
	}
}

static t_list	*copy_shallow_list(t_list *env_list)
{
	t_list	*copy;
	t_list	*new_node;

	copy = NULL;
	while (env_list)
	{
		new_node = ft_lstnew(env_list->content);
		if (!new_node)
		{
			free_shallow_list(copy);
			return (NULL);
		}
		ft_lstadd_back(&copy, new_node);
		env_list = env_list->next;
	}
	return (copy);
}

static int	wrapperkey_cmp(void *a, void *b)
{
	t_env_entry	*entry_a;
	t_env_entry	*entry_b;

	entry_a = (t_env_entry *)a;
	entry_b = (t_env_entry *)b;
	return (ft_strcmp(entry_a->key, entry_b->key));
}

static void	write_sorted_list(t_list *sorted_list, int fd)
{
	t_env_entry	*entry;

	while (sorted_list)
	{
		entry = (t_env_entry *)sorted_list->content;
		ft_putstr_fd("declare -x ", fd);
		ft_putstr_fd(entry->key, fd);
		if (entry->value != NULL)
		{
			ft_putstr_fd("=\"", fd);
			ft_putstr_fd(entry->value, fd);
			ft_putstr_fd("\"", fd);
		}
		ft_putstr_fd("\n", fd);
		sorted_list = sorted_list->next;
	}
}

int	print_sorted_exports(t_list *env_list, int fd[2])
{
	t_list	*sorted_list;
	t_list	*head;

	sorted_list = copy_shallow_list(env_list);
	if (!sorted_list)
	{
		print_err("export: write error: "
			"No space left on device\n");
		set_exit_status(1);
		return (1);
	}
	ft_lstsort(&sorted_list, wrapperkey_cmp);
	head = sorted_list;
	write_sorted_list(sorted_list, fd[1]);
	free_shallow_list(head);
	set_exit_status(0);
	return (0);
}
