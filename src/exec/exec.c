/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 14:00:01 by aserbest          #+#    #+#             */
/*   Updated: 2025/07/27 18:47:34 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void	init_pipe_values(int *prev_pipe, int *curr_pipe)
{
	prev_pipe[0] = -1;
	prev_pipe[1] = -1;
	curr_pipe[0] = -1;
	curr_pipe[1] = -1;
}

int	create_pipe(t_cmd *cur, int *cur_pipe)
{
	if (cur->next)
	{
		if (pipe(cur_pipe) == -1)
		{
			perror("pipe");
			setup_signals_prompt();
			return (1);
		}
	}
	return (0);
}

void	multi_cmd_parent(t_cmd *curr, int *prev_pipe, int *cur_pipe)
{
	if (curr->input != STDIN_FILENO)
		close(curr->input);
	if (curr->output != STDOUT_FILENO)
		close(curr->output);
	if (prev_pipe[0] != -1)
		close(prev_pipe[0]);
	if (prev_pipe[1] != -1)
		close(prev_pipe[1]);
	prev_pipe[0] = cur_pipe[0];
	prev_pipe[1] = cur_pipe[1];
	cur_pipe[0] = -1;
	cur_pipe[1] = -1;
	if (curr->next && prev_pipe[1] != -1)
	{
		close(prev_pipe[1]);
		prev_pipe[1] = -1;
	}
}

static int	execute_pipeline(t_cmd *cmd_list)
{
	t_cmd	*cur;
	int		prev_pipe[2];
	int		cur_pipe[2];
	int		exit_status;

	setup_signals_parent_ignore();
	init_pipe_values(prev_pipe, cur_pipe);
	cur = cmd_list;
	while (cur)
	{
		if (create_pipe(cur, cur_pipe) == 1)
			return (1);
		cur->pid = fork();
		if (cur->pid == 0)
			execute_child(cur, prev_pipe, cur_pipe);
		else if (cur->pid > 0)
			multi_cmd_parent(cur, prev_pipe, cur_pipe);
		else
			return (fork_error(prev_pipe, cur_pipe));
		cur = cur->next;
	}
	exit_status = wait_for_children(cmd_list);
	setup_signals_prompt();
	return (exit_status);
}

int	execute(t_cmd *cmd_list)
{
	int	exit_status;

	if (!cmd_list)
		return (0);
	if (!cmd_list->next)
		exit_status = execute_single_cmd(cmd_list);
	else
		exit_status = execute_pipeline(cmd_list);
	set_exit_status(exit_status);
	return (exit_status);
}
