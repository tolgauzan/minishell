/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:55:26 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:55:26 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "minishell_constants.h"
#include <stdlib.h>
#include <unistd.h>

static char	*build_prompt(char *user, char *path)
{
	char	*temp1;
	char	*temp2;
	char	*prompt;

	temp1 = gc_safe(ft_strjoin(G, user));
	temp2 = gc_safe(ft_strjoin(temp1, G));
	gc_free(temp1);
	temp1 = gc_safe(ft_strjoin(temp2, H));
	gc_free(temp2);
	temp2 = gc_safe(ft_strjoin(temp1, B));
	gc_free(temp1);
	temp1 = gc_safe(ft_strjoin(temp2, path));
	gc_free(temp2);
	temp2 = gc_safe(ft_strjoin(temp1, R));
	gc_free(temp1);
	prompt = gc_safe(ft_strjoin(temp2, P));
	gc_free(temp2);
	return (prompt);
}

static char	*process_path_with_home(char *cwd, char *home, size_t home_len)
{
	char	*tilde;
	size_t	tail_len;

	if (ft_strncmp(cwd, home, home_len) == 0
		&& (cwd[home_len] == '\0' || cwd[home_len] == '/'))
	{
		if (ft_strcmp(cwd, home) == 0)
			return (gc_safe(ft_strdup("~")));
		tail_len = ft_strlen(cwd) - home_len;
		tilde = gc_safe(gc_malloc(tail_len + 2));
		tilde[0] = '~';
		ft_strcpy(tilde + 1, cwd + home_len);
		return (tilde);
	}
	return (gc_safe(ft_strdup(cwd)));
}

static char	*get_display_path(void)
{
	char	*cwd;
	char	*home;
	char	*result;
	size_t	home_len;

	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (gc_safe(ft_strdup(".")));
	home = get_env_value("HOME");
	if (!home)
		result = gc_safe(ft_strdup(cwd));
	else
	{
		home_len = ft_strlen(home);
		result = process_path_with_home(cwd, home, home_len);
	}
	free(cwd);
	return (result);
}

char	*generate_prompt(void)
{
	char	*env_user;
	char	*user;
	char	*path;
	char	*prompt;

	env_user = get_env_value("USER");
	if (env_user && *env_user)
		user = gc_safe(ft_strdup(env_user));
	else
		user = gc_safe(ft_strdup("minishell"));
	path = get_display_path();
	prompt = build_prompt(user, path);
	gc_free(user);
	gc_free(path);
	return (prompt);
}
