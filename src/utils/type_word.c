/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_type.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 06:31:22 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/11 06:31:22 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_word(t_token_type type)
{
	return (type == T_UQUOTE_WORD
		|| type == T_SQUOTE_WORD
		|| type == T_DQUOTE_WORD);
}

int	is_quoted(t_token_type type)
{
	return (type == T_SQUOTE_WORD || type == T_DQUOTE_WORD);
}

int	is_empty_unquoted(t_token *token)
{
	return (token->value
		&& token->value[0] == '\0'
		&& token->type == T_UQUOTE_WORD
		&& !is_after_redir(token));
}

int	is_ambiguous_redir_token(t_token *token, char *expanded)
{
	return (expanded
		&& *expanded == '\0'
		&& token->type == T_UQUOTE_WORD
		&& token->was_expanded == 1
		&& is_after_redir(token));
}

int	is_separator_token(t_token *token)
{
	return (is_separator(token->type));
}
