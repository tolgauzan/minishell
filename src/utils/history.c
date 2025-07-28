/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 09:45:24 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/17 09:45:24 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**get_last_history_line(void)
{
	static char	*g_last_history_line = NULL;

	return (&g_last_history_line);
}

int	should_add_to_history(char *line)
{
	if (!line)
		return (0);
	if (*line == '\0' || is_only_spaces(line))
		return (0);
	if (line[0] && is_whitespaces(line[0]))
		return (0);
	if (line[0] == '^')
		return (0);
	if (*get_last_history_line()
		&& ft_strcmp(*get_last_history_line(), line) == 0)
		return (0);
	if (*get_last_history_line())
		gc_free(*get_last_history_line());
	*get_last_history_line() = gc_safe(ft_strdup(line));
	return (1);
}

void	cleanup_ignoreboth_history(void)
{
	if (*get_last_history_line())
	{
		gc_free(*get_last_history_line());
		*get_last_history_line() = NULL;
	}
}
