/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenize_operator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:54:57 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:54:57 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdint.h>

t_error	tokenize_w_spaces(t_token **token_list, char *line, size_t *i)
{
	t_token	*token;
	size_t	start;

	start = *i;
	while (line[*i] && is_whitespaces(line[*i]))
		(*i)++;
	if (*i > start)
	{
		token = create_token(NULL, T_SEPARATOR);
		add_token_list_back(token_list, token);
	}
	(*i)--;
	return (E_SUCCESS);
}

t_error	tokenize_s_word(t_token **token_list, char *line, size_t *i)
{
	t_token	*token;
	size_t	start_i;
	size_t	close_i;
	char	*value;

	start_i = *i;
	close_i = find_quote_end(line, start_i, '\'');
	if (close_i == SIZE_MAX)
		return (E_QUOTE_SQUOTE);
	value = gc_safe(ft_substr(line, (start_i + 1), (close_i - start_i - 1)));
	token = create_token(value, T_SQUOTE_WORD);
	add_token_list_back(token_list, token);
	*i = close_i;
	return (E_SUCCESS);
}

t_error	tokenize_d_word(t_token **token_list, char *line, size_t *i)
{
	t_token	*token;
	size_t	start_i;
	size_t	close_i;
	char	*value;

	start_i = *i;
	close_i = find_quote_end(line, start_i, '"');
	if (close_i == SIZE_MAX)
		return (E_QUOTE_DQUOTE);
	value = gc_safe(ft_substr(line, (start_i + 1), (close_i - start_i - 1)));
	token = create_token(value, T_DQUOTE_WORD);
	add_token_list_back(token_list, token);
	*i = close_i;
	return (E_SUCCESS);
}

t_error	tokenize_u_word(t_token **token_list, char *line, size_t *i)
{
	t_token	*token;
	size_t	start_i;
	char	*value;

	start_i = *i;
	while (line[*i])
	{
		if (is_escape_sequence(line, *i))
			*i += 2;
		else if (is_meta_char(line[*i]))
			break ;
		else
			(*i)++;
	}
	if (*i == start_i)
		return (E_SUCCESS);
	value = create_unquoted_word(line, start_i, *i);
	token = create_token(value, T_UQUOTE_WORD);
	add_token_list_back(token_list, token);
	(*i)--;
	return (E_SUCCESS);
}
