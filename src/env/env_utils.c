/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:52:23 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:52:23 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	env_free_node(t_list *node)
{
	t_env_entry	*entry;

	if (!node)
		return ;
	entry = (t_env_entry *)node->content;
	gc_free(entry->key);
	gc_free(entry->value);
	gc_free(entry);
	gc_free(node);
}

void	unset_env(char *key)
{
	t_env_entry	*entry;
	t_list		*prev;
	t_list		*curr;

	if (!key || !*key)
		return ;
	prev = NULL;
	curr = *get_env();
	while (curr)
	{
		entry = (t_env_entry *)curr->content;
		if (entry && ft_strcmp(entry->key, key) == 0)
		{
			if (prev)
				prev->next = curr->next;
			else
				*get_env() = curr->next;
			env_free_node(curr);
			return ;
		}
		prev = curr;
		curr = curr->next;
	}
}

void	export_env(char *keyvalue)
{
	t_list		*existing;
	t_list		*new_node;
	char		*equal_pos;

	if (!keyvalue || !*keyvalue)
		return ;
	equal_pos = ft_strchr(keyvalue, '=');
	if (equal_pos)
	{
		new_node = create_env_node(keyvalue);
		unset_env(((t_env_entry *)new_node->content)->key);
		ft_lstadd_back(get_env(), new_node);
	}
	else
	{
		existing = get_env_node(keyvalue);
		if (!existing)
		{
			new_node = create_env_node(keyvalue);
			ft_lstadd_back(get_env(), new_node);
		}
	}
}

t_list	*get_env_node(char *key)
{
	t_env_entry	*entry;
	t_list		*node;

	if (!key)
		return (NULL);
	node = *get_env();
	while (node)
	{
		entry = (t_env_entry *)node->content;
		if (entry && ft_strcmp(entry->key, key) == 0)
			return (node);
		node = node->next;
	}
	return (NULL);
}

char	*get_env_value(char *key)
{
	t_env_entry	*entry;
	t_list		*node;

	if (!key)
		return (NULL);
	node = get_env_node(key);
	if (!node)
		return (NULL);
	entry = (t_env_entry *)node->content;
	if (!entry)
		return (NULL);
	return (entry->value);
}
