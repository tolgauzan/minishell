/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 05:19:50 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/11 05:19:50 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_error	get_token_syntax_error(t_token_type type)
{
	if (type == T_PIPE)
		return (E_SYNTAX_PIPE);
	if (type == T_REDIR_IN)
		return (E_SYNTAX_REDIR_IN);
	if (type == T_REDIR_OUT)
		return (E_SYNTAX_REDIR_OUT);
	if (type == T_REDIR_APPEND)
		return (E_SYNTAX_REDIR_APPEND);
	if (type == T_HEREDOC)
		return (E_SYNTAX_HEREDOC);
	return (E_SYNTAX_NEWLINE);
}

static t_error	process_operator_token(t_token *curr, t_token *next)
{
	if (!next)
		return (E_SYNTAX_NEWLINE);
	if (is_pipe(curr->type))
	{
		if (is_pipe(next->type))
			return (E_SYNTAX_PIPE);
	}
	else if (is_redir(curr->type))
	{
		if (is_operator(next->type))
			return (get_token_syntax_error(next->type));
		if (!is_word(next->type))
			return (get_token_syntax_error(curr->type));
	}
	return (E_SUCCESS);
}

t_error	validate_syntax(t_token *token_list)
{
	t_token	*curr;
	t_token	*next;
	t_error	err;

	curr = token_list;
	if (is_pipe(curr->type))
		return (E_SYNTAX_PIPE);
	while (curr)
	{
		next = skip_separators(curr->next);
		if (is_operator(curr->type))
		{
			err = process_operator_token(curr, next);
			if (err)
				return (err);
		}
		curr = skip_separators(curr->next);
	}
	return (E_SUCCESS);
}
