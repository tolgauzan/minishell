/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 13:42:39 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/19 13:42:39 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_after_redir(t_token *token)
{
	t_token	*prev;

	if (!token || !token->prev)
		return (0);
	prev = token->prev;
	while (prev && is_separator(prev->type))
		prev = prev->prev;
	return (prev && is_redir(prev->type));
}

int	is_after_heredoc(t_token *token)
{
	t_token	*prev;

	if (!token || !token->prev)
		return (0);
	prev = token->prev;
	while (prev && is_separator(prev->type))
		prev = prev->prev;
	return (prev && prev->type == T_HEREDOC);
}

static void	free_token_from_list(t_token **head, t_token *target)
{
	if (!head || !*head || !target)
		return ;
	if (*head == target)
		*head = target->next;
	if (target->prev)
		target->prev->next = target->next;
	if (target->next)
		target->next->prev = target->prev;
	if (target->value)
		gc_free(target->value);
	gc_free(target);
}

void	free_tokens_if(t_token **token_list, int (*condition)(t_token *))
{
	t_token	*curr;
	t_token	*next;

	if (!token_list || !*token_list || !condition)
		return ;
	curr = *token_list;
	while (curr)
	{
		next = curr->next;
		if (condition(curr))
			free_token_from_list(token_list, curr);
		curr = next;
	}
}

void	merge_word(t_token **token_list)
{
	t_token	*curr;
	t_token	*next_word;
	char	*merged_value;

	if (!token_list || !*token_list)
		return ;
	curr = *token_list;
	while (curr)
	{
		if (is_word(curr->type) && curr->next && is_word(curr->next->type))
		{
			next_word = curr->next;
			merged_value = gc_safe(ft_strjoin(curr->value, next_word->value));
			gc_free(curr->value);
			curr->value = merged_value;
			free_token_from_list(token_list, next_word);
			continue ;
		}
		curr = curr->next;
	}
}
