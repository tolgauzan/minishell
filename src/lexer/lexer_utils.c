/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:44 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:44 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdint.h>

t_token	*skip_separators(t_token *token)
{
	while (token && is_separator(token->type))
		token = token->next;
	return (token);
}

size_t	find_quote_end(char *ln, size_t start, char quote)
{
	size_t	i;

	if (!ln || !quote)
		return (SIZE_MAX);
	i = (start + 1);
	while (ln[i] && ln[i] != quote)
		i++;
	if (!ln[i])
		return (SIZE_MAX);
	return (i);
}

t_token	*find_pipe(t_token *start)
{
	t_token	*curr;

	curr = start;
	while (curr)
	{
		if (curr->type == T_PIPE)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}
