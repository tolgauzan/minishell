/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 00:17:44 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/10 00:17:44 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_env_string(char *key, char *value)
{
	char	*temp;
	char	*env_string;
	char	*temp_value;

	if (value == NULL)
		temp_value = "";
	else
		temp_value = value;
	temp = gc_safe(ft_strjoin(key, "="));
	env_string = gc_safe(ft_strjoin(temp, temp_value));
	gc_free(temp);
	return (env_string);
}

static void	fill_env_array(char **env_array, t_list *env_list, int count)
{
	t_list		*current;
	t_env_entry	*entry;
	int			i;

	i = 0;
	current = env_list;
	while (current && i < count)
	{
		entry = (t_env_entry *)current->content;
		if (entry && entry->key)
			env_array[i++] = create_env_string(entry->key, entry->value);
		current = current->next;
	}
	env_array[i] = NULL;
}

char	**env_to_array(void)
{
	t_list	*env_list;
	char	**env_array;
	int		count;

	env_list = *get_env();
	count = ft_lstsize(env_list);
	if (count == 0)
	{
		env_array = gc_malloc(sizeof(char *) * 1);
		env_array[0] = NULL;
		return (env_array);
	}
	env_array = gc_malloc(sizeof(char *) * (count + 1));
	fill_env_array(env_array, env_list, count);
	return (env_array);
}
