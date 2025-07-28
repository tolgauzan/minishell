/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:54:10 by aserbest          #+#    #+#             */
/*   Updated: 2025/07/27 18:52:42 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdlib.h>
#include <unistd.h>

static void	setup_input_fds(t_cmd *cmd, int *prev_pipe)
{
	if (cmd->input != STDIN_FILENO)
	{
		dup2(cmd->input, STDIN_FILENO);
		close(cmd->input);
	}
	else if (prev_pipe && prev_pipe[0] != -1)
	{
		dup2(prev_pipe[0], STDIN_FILENO);
		close(prev_pipe[0]);
	}
}

static void	setup_output_fds(t_cmd *cmd, int *curr_pipe)
{
	if (cmd->output != STDOUT_FILENO)
	{
		dup2(cmd->output, STDOUT_FILENO);
		close(cmd->output);
	}
	else if (curr_pipe && curr_pipe[1] != -1)
	{
		dup2(curr_pipe[1], STDOUT_FILENO);
		close(curr_pipe[1]);
	}
}

static void	setup_child_fds(t_cmd *cmd, int *prev_pipe, int *curr_pipe)
{
	setup_input_fds(cmd, prev_pipe);
	setup_output_fds(cmd, curr_pipe);
	if (prev_pipe)
	{
		if (prev_pipe[0] != -1)
			close(prev_pipe[0]);
		if (prev_pipe[1] != -1)
			close(prev_pipe[1]);
	}
	if (curr_pipe)
	{
		if (curr_pipe[0] != -1)
			close(curr_pipe[0]);
		if (curr_pipe[1] != -1)
			close(curr_pipe[1]);
	}
}

void	execute_child(t_cmd *cmd, int *prev_pipe, int *curr_pipe)
{
	char	*path;
	int		empty_cmd_status;

	setup_signals_execute_child();
	if (process_cmd_redirections(cmd))
		exit(1);
	setup_child_fds(cmd, prev_pipe, curr_pipe);
	empty_cmd_status = check_empty_command(cmd);
	if (empty_cmd_status != 0)
		exit(empty_cmd_status);
	if (!cmd->args || !cmd->args[0])
		exit(0);
	if (is_builtin(cmd->args[0]))
		builtin_for_child(cmd);
	if (ft_strchr(cmd->args[0], '/'))
		direct_path(cmd);
	else
	{
		path = find_path(cmd->args[0]);
		if (!path)
			command_not_found(cmd);
		execute_external_command(cmd, path);
	}
}
