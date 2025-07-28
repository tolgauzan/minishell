/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:03:46 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 12:03:46 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_redir_type	get_redir_type(t_token_type token_type)
{
	if (token_type == T_REDIR_IN)
		return (REDIR_INPUT);
	else if (token_type == T_REDIR_OUT)
		return (REDIR_OUTPUT);
	else if (token_type == T_REDIR_APPEND)
		return (REDIR_APPEND);
	else
		return (REDIR_HEREDOC);
}

static int	count_redirs_in_cmd(t_token *start, t_token *end)
{
	t_token	*curr;
	int		count;

	count = 0;
	curr = start;
	while (curr && curr != end)
	{
		if (is_redir(curr->type))
			count++;
		curr = curr->next;
	}
	return (count);
}

static void	fill_redirs(t_cmd *cmd, t_token *start, t_token *end)
{
	t_token	*curr;
	t_token	*file_token;
	int		redir_i;

	redir_i = 0;
	curr = start;
	while (curr && curr != end && redir_i < cmd->redir_count)
	{
		if (is_redir(curr->type))
		{
			cmd->redirs[redir_i].type = get_redir_type(curr->type);
			file_token = curr->next;
			if (file_token && is_word(file_token->type))
			{
				cmd->redirs[redir_i].filename = file_token->value;
				cmd->redirs[redir_i].is_quoted = is_quoted(
						file_token->type);
				cmd->redirs[redir_i].was_expanded = file_token->was_expanded;
				cmd->redirs[redir_i].heredoc_read_fd = -1;
				redir_i++;
			}
		}
		curr = curr->next;
	}
}

void	parse_redirs(t_cmd *cmd, t_token *start, t_token *end)
{
	cmd->redir_count = count_redirs_in_cmd(start, end);
	if (cmd->redir_count == 0)
	{
		cmd->redirs = NULL;
		return ;
	}
	cmd->redirs = gc_safe(
			ft_calloc(cmd->redir_count, sizeof(t_redir)));
	fill_redirs(cmd, start, end);
}
