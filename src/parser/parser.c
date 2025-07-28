/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tuzan <tuzan@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 11:55:17 by tuzan             #+#    #+#             */
/*   Updated: 2025/07/06 11:55:17 by tuzan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

void	free_cmds(t_cmd **cmd_list)
{
	t_cmd	*curr;
	t_cmd	*next;

	if (!cmd_list || !*cmd_list)
		return ;
	curr = *cmd_list;
	while (curr)
	{
		next = curr->next;
		gc_free(curr->args);
		gc_free(curr->redirs);
		gc_free(curr);
		curr = next;
	}
	*cmd_list = NULL;
}

static t_cmd	*create_cmd(void)
{
	t_cmd	*node;

	node = (t_cmd *)gc_safe(ft_calloc(1, sizeof(t_cmd)));
	node->input = STDIN_FILENO;
	node->output = STDOUT_FILENO;
	node->pid = -1;
	return (node);
}

static void	add_cmd_list_back(t_cmd **cmd_list, t_cmd *new_cmd)
{
	t_cmd	*curr;

	if (!cmd_list || !new_cmd)
		return ;
	if (!*cmd_list)
	{
		*cmd_list = new_cmd;
		return ;
	}
	curr = *cmd_list;
	while (curr->next)
		curr = curr->next;
	curr->next = new_cmd;
	new_cmd->prev = curr;
}

static void	parse_cmd_segment(t_cmd **head, t_token *start,
										t_token *end)
{
	t_cmd	*cmd;

	cmd = create_cmd();
	parse_args(cmd, start, end);
	parse_redirs(cmd, start, end);
	add_cmd_list_back(head, cmd);
}

void	parse(t_cmd **cmd_list, t_token *token_list)
{
	t_token	*curr;
	t_token	*pipe_token;

	*cmd_list = NULL;
	curr = token_list;
	while (curr)
	{
		pipe_token = find_pipe(curr);
		parse_cmd_segment(cmd_list, curr, pipe_token);
		if (pipe_token)
			curr = pipe_token->next;
		else
			break ;
	}
}
