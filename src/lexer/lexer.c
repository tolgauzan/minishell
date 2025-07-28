/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:47 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:47 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tokens(t_token **token_list)
{
	t_token	*curr;
	t_token	*next;

	if (!token_list || !*token_list)
		return ;
	curr = *token_list;
	while (curr)
	{
		next = curr->next;
		if (curr->value)
		{
			gc_free(curr->value);
			curr->value = NULL;
		}
		gc_free(curr);
		curr = next;
	}
	*token_list = NULL;
}

t_token	*create_token(char *value, t_token_type type)
{
	t_token	*token;

	token = (t_token *)gc_safe(ft_calloc(1, sizeof(t_token)));
	token->value = value;
	token->type = type;
	token->was_expanded = 0;
	return (token);
}

void	add_token_list_back(t_token **token_list, t_token *new_token)
{
	t_token	*curr;

	if (!token_list || !new_token)
		return ;
	if (!*token_list)
	{
		*token_list = new_token;
		return ;
	}
	curr = *token_list;
	while (curr->next)
		curr = curr->next;
	curr->next = new_token;
	new_token->prev = curr;
}

static t_error	dispatch_tokenizer(t_token **token_list, char *line, size_t *i)
{
	if (is_whitespaces(line[*i]))
		return (tokenize_w_spaces(token_list, line, i));
	if (is_redir_char(line[*i]))
		return (tokenize_redir(token_list, line, i));
	if (line[*i] == '|')
		return (tokenize_pipe(token_list, line, i));
	if (line[*i] == '\'')
		return (tokenize_s_word(token_list, line, i));
	if (line[*i] == '"')
		return (tokenize_d_word(token_list, line, i));
	return (tokenize_u_word(token_list, line, i));
}

t_error	lex(t_token **token_list, char *line)
{
	t_error	err;
	size_t	i;

	i = 0;
	*token_list = NULL;
	if (is_only_spaces(line))
		return (E_EMPTY);
	while (line[i])
	{
		err = dispatch_tokenizer(token_list, line, &i);
		if (err)
			return (err);
		i++;
	}
	return (validate_syntax(*token_list));
}
