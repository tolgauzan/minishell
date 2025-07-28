/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:52:26 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:52:26 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

t_list	**get_env(void)
{
	static t_list	*env = NULL;

	return (&env);
}

t_list	*create_env_node(char *keyvalue)
{
	t_env_entry	*entry;
	char		*equal_pos;

	entry = gc_safe(ft_calloc(1, sizeof(t_env_entry)));
	equal_pos = ft_strchr(keyvalue, '=');
	if (equal_pos)
	{
		entry->key = gc_safe(ft_substr(keyvalue, 0, equal_pos - keyvalue));
		entry->value = gc_safe(ft_strdup(equal_pos + 1));
	}
	else
	{
		entry->key = gc_safe(ft_strdup(keyvalue));
		entry->value = NULL;
	}
	return (gc_safe(ft_lstnew(entry)));
}

static void	ensure_env_defaults(void)
{
	char	*env_var;
	char	*cwd;
	char	*shlvl_str;

	if (!get_env_value("OLDPWD"))
		export_env("OLDPWD");
	if (!get_env_value("PWD"))
	{
		cwd = gc_safe(getcwd(NULL, 0));
		env_var = gc_safe(ft_strjoin("PWD=", cwd));
		export_env(env_var);
		gc_free(env_var);
		gc_free(cwd);
	}
	if (!get_env_value("SHLVL"))
		export_env("SHLVL=1");
	else
	{
		shlvl_str = gc_safe(ft_itoa(ft_atoi(get_env_value("SHLVL")) + 1));
		env_var = gc_safe(ft_strjoin("SHLVL=", shlvl_str));
		export_env(env_var);
		gc_free(env_var);
		gc_free(shlvl_str);
	}
}

void	init_env(char **envp)
{
	t_list	**env;

	env = get_env();
	*env = NULL;
	while (*envp)
	{
		ft_lstadd_back(env, create_env_node(*envp));
		envp++;
	}
	ensure_env_defaults();
}
