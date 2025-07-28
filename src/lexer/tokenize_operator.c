/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:55:01 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:55:01 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_token_type	get_redirection_type(char *line, size_t i)
{
	if (line[i] == '<')
	{
		if (line[i + 1] == '<')
			return (T_HEREDOC);
		return (T_REDIR_IN);
	}
	else
	{
		if (line[i + 1] == '>')
			return (T_REDIR_APPEND);
		return (T_REDIR_OUT);
	}
}

t_error	tokenize_redir(t_token **token_list, char *line, size_t *i)
{
	t_token			*token;
	t_token_type	type;
	char			*value;
	size_t			advance;

	advance = 1;
	type = get_redirection_type(line, *i);
	if (type == T_HEREDOC || type == T_REDIR_APPEND)
		advance = 2;
	if (type == T_HEREDOC)
		value = gc_safe(ft_strdup("<<"));
	else if (type == T_REDIR_APPEND)
		value = gc_safe(ft_strdup(">>"));
	else if (type == T_REDIR_IN)
		value = gc_safe(ft_strdup("<"));
	else
		value = gc_safe(ft_strdup(">"));
	token = create_token(value, type);
	add_token_list_back(token_list, token);
	*i += advance - 1;
	return (E_SUCCESS);
}

t_error	tokenize_pipe(t_token **token_list, char *line, size_t *i)
{
	t_token	*token;
	char	*value;

	(void)line;
	(void)i;
	value = gc_safe(ft_strdup("|"));
	token = create_token(value, T_PIPE);
	add_token_list_back(token_list, token);
	return (E_SUCCESS);
}
