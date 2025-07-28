/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aserbest <aserbest@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 15:14:00 by aserbest          #+#    #+#             */
/*   Updated: 2025/07/27 18:57:30 by aserbest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include "minishell.h"

void	direct_path(t_cmd *cmd)
{
	struct stat	file_stat;

	if (access(cmd->args[0], F_OK) == 0)
	{
		if (stat(cmd->args[0], &file_stat) == 0)
		{
			if (S_ISDIR(file_stat.st_mode))
				is_a_directory(cmd);
			else if (access(cmd->args[0], X_OK) == 0)
				execute_external_command(cmd, ft_strdup(cmd->args[0]));
			else
				permission_denied(cmd);
		}
		else
			no_such_file_or_dir(cmd);
	}
	else
		no_such_file_or_dir(cmd);
}

void	builtin_for_child(t_cmd *cmd)
{
	int	fd[2];

	fd[0] = STDIN_FILENO;
	fd[1] = STDOUT_FILENO;
	exec_builtin(cmd, fd, 0);
	exit(get_exit_status());
}

int	check_empty_command(t_cmd *cmd)
{
	if (!cmd->args || !cmd->args[0])
		return (0);
	if (*(cmd->args[0]) == '\0')
	{
		print_err("-minishell: ");
		print_err(cmd->args[0]);
		print_err(": command not found\n");
		return (127);
	}
	return (0);
}

void	execute_external_command(t_cmd *cmd, char *path)
{
	char	**envp;

	envp = env_to_array();
	execve(path, cmd->args, envp);
	execve_error(cmd);
}

int	fork_error(int *prev_pipe, int *cur_pipe)
{
	perror("-minishell: fork");
	if (prev_pipe)
	{
		if (prev_pipe[0] != -1)
			close(prev_pipe[0]);
		if (prev_pipe[1] != -1)
			close(prev_pipe[1]);
	}
	if (cur_pipe)
	{
		if (cur_pipe[0] != -1)
			close(cur_pipe[0]);
		if (cur_pipe[1] != -1)
			close(cur_pipe[1]);
	}
	setup_signals_prompt();
	return (1);
}
