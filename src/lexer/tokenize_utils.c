/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 12:19:18 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/07 12:19:18 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stddef.h>

int	is_escape_sequence(char *line, size_t i)
{
	return (line[i] == '\\' && line[i + 1] != '\0');
}

static size_t	unquoted_length(char *line, size_t start, size_t end)
{
	size_t	len;
	size_t	i;

	len = 0;
	i = start;
	while (i < end)
	{
		if (is_escape_sequence(line, i) && i + 1 < end)
			i += 2;
		else
			i++;
		len++;
	}
	return (len);
}

char	*create_unquoted_word(char *line, size_t start, size_t end)
{
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	len = unquoted_length(line, start, end);
	str = gc_safe(ft_calloc(len + 1, sizeof(char)));
	i = start;
	j = 0;
	while (i < end)
	{
		if (is_escape_sequence(line, i) && i + 1 < end)
		{
			str[j++] = line[i + 1];
			i += 2;
		}
		else
		{
			str[j++] = line[i++];
		}
	}
	return (str);
}
