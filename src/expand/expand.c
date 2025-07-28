/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:15 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:15 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>

static char	*get_variable_key(char *str, size_t *i)
{
	size_t	start;

	start = *i;
	while (str && str[*i] && is_var_char(str[*i]))
		(*i)++;
	return (ft_substr(str, start, *i - start));
}

static char	*get_special_variable(char *str, size_t *i)
{
	if (str[*i] == '?')
	{
		(*i)++;
		return (ft_itoa(get_exit_status()));
	}
	return (NULL);
}

char	*expand_var(char *str, size_t *i)
{
	char	*var_key;
	char	*var_value;

	if (str[*i] != '$')
		return (NULL);
	(*i)++;
	var_value = get_special_variable(str, i);
	if (var_value)
		return (var_value);
	if (!is_var_start(str[*i]))
		return (ft_strdup("$"));
	var_key = get_variable_key(str, i);
	if (!var_key)
		return (NULL);
	var_value = get_env_value(var_key);
	free(var_key);
	if (!var_value)
		return (ft_strdup(""));
	return (ft_strdup(var_value));
}

static int	should_expand_token(t_token *token)
{
	if (token->type == T_SQUOTE_WORD)
		return (0);
	if (is_operator(token->type))
		return (0);
	if (is_separator(token->type))
		return (0);
	if (is_after_heredoc(token))
		return (0);
	return (token->type == T_DQUOTE_WORD || token->type == T_UQUOTE_WORD);
}

void	expand(t_token **token_list)
{
	t_token	*token;
	char	*expanded;

	token = *token_list;
	while (token)
	{
		if (should_expand_token(token))
		{
			expanded = gc_safe(expand_str(token->value));
			if (expanded && ft_strcmp(expanded, token->value) != 0)
				token->was_expanded = 1;
			if (is_ambiguous_redir_token(token, expanded))
			{
				gc_free(expanded);
				token = token->next;
				continue ;
			}
			gc_free(token->value);
			token->value = expanded;
		}
		token = token->next;
	}
	free_tokens_if(token_list, is_empty_unquoted);
	merge_word(token_list);
	free_tokens_if(token_list, is_separator_token);
}
