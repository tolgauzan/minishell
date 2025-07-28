/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_single_cmd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 13:48:32 by aserbest          #+#    #+#             */
/*   Updated: 2025/07/27 18:48:34 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <unistd.h>

static int	handle_no_args(t_cmd *cmd)
{
	if (process_cmd_redirections(cmd))
		return (get_exit_status());
	if (cmd->input != STDIN_FILENO)
		close(cmd->input);
	if (cmd->output != STDOUT_FILENO)
		close(cmd->output);
	return (0);
}

static int	empty_string_cmd(t_cmd *cmd, int empty_cmd_status)
{
	if (process_cmd_redirections(cmd))
		return (get_exit_status());
	if (cmd->input != STDIN_FILENO)
		close(cmd->input);
	if (cmd->output != STDOUT_FILENO)
		close(cmd->output);
	set_exit_status(empty_cmd_status);
	return (empty_cmd_status);
}

static int	execute_single_builtin(t_cmd *cmd)
{
	int	fd[2];

	if (process_cmd_redirections(cmd))
		return (get_exit_status());
	if (cmd->input != STDIN_FILENO)
		fd[0] = cmd->input;
	else
		fd[0] = STDIN_FILENO;
	if (cmd->output != STDOUT_FILENO)
		fd[1] = cmd->output;
	else
		fd[1] = STDOUT_FILENO;
	exec_builtin(cmd, fd, 1);
	if (cmd->input != STDIN_FILENO)
		close(cmd->input);
	if (cmd->output != STDOUT_FILENO)
		close(cmd->output);
	return (get_exit_status());
}

static int	single_cmd_parent(t_cmd *cmd)
{
	int	exit_status;

	exit_status = wait_for_child(cmd->pid);
	setup_signals_prompt();
	return (exit_status);
}

int	execute_single_cmd(t_cmd *cmd)
{
	int	empty_cmd_status;

	if (!cmd->args || !cmd->args[0])
		return (handle_no_args(cmd));
	empty_cmd_status = check_empty_command(cmd);
	if (empty_cmd_status != 0)
		return (empty_string_cmd(cmd, empty_cmd_status));
	if (is_builtin(cmd->args[0]))
		return (execute_single_builtin(cmd));
	cmd->pid = fork();
	if (cmd->pid == 0)
		execute_child(cmd, NULL, NULL);
	else if (cmd->pid > 0)
	{
		setup_signals_parent_ignore();
		return (single_cmd_parent(cmd));
	}
	else
		return (fork_error(NULL, NULL));
	return (1);
}
